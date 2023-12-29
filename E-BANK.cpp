#include <stdio.h>
#include <string.h>
typedef struct {
    char type[20];
    double amount;
} Transaction;
typedef struct {
    int numcompte;
    char nom[50];
    char prenom[50];
    double balance;
    Transaction transactions[100];
    int transactionCount;
} Client;
void creerCompte(Client *clients, int *numclients) {
    if (*numclients < 100) {
        (*numclients)++;
        clients[*numclients - 1].numcompte = *numclients;

        printf("Nom : ");
        scanf("%s", clients[*numclients - 1].nom);

        printf("Pr�nom : ");
        scanf("%s", clients[*numclients - 1].prenom);

        printf("Solde initial : ");
        scanf("%lf", &clients[*numclients - 1].balance);

        printf("\nCompte cr�� avec succ�s. Num�ro de compte : %d\n", *numclients);
    } else {
        printf("D�sol�, le nombre maximal de clients a �t� atteint. Impossible de cr�er un nouveau compte.\n");
    }
}
void mettreAJour(Client *clients, int numclients) {
    int compteAchanger;
    printf("Entrez le num�ro de compte � mettre � jour : ");
    scanf("%d", &compteAchanger);

    for (int i = 0; i < numclients; i++) {
        if (clients[i].numcompte == compteAchanger) {
            printf("Nouveau solde : ");
            scanf("%lf", &clients[i].balance);
            printf("Informations mises � jour avec succ�s pour le compte %d.\n", compteAchanger);
            return;
        }
    }
    printf("Compte non trouv�.\n");
}
void calculerInterets(Client *clients, int numclients) {
    int numcompte;
    printf("Entrez le num�ro de compte pour calculer les int�r�ts : ");
    scanf("%d", &numcompte);

    for (int i = 0; i < numclients; i++) {
        if (clients[i].numcompte == numcompte) {
            double interest = clients[i].balance * 0.05;
            clients[i].balance += interest;
            strcpy(clients[i].transactions[clients[i].transactionCount].type, "Interest");
            clients[i].transactions[clients[i].transactionCount].amount = interest;
            clients[i].transactionCount++;
            printf("Int�r�ts calcul�s avec succ�s. Nouveau solde : %.2lf\n", clients[i].balance);
            return;
        }
    }
    printf("Compte non trouv�.\n");
}
void gererTransactions(Client *clients, int numclients) {
    int numcompte;
    int Typetransaction;
    double amount;
    printf("\nGestion des transactions bancaires :\n");
    printf("Entrez le num�ro de compte : ");
    scanf("%d", &numcompte);
    int accountIndex = -1;
    for (int i = 0; i < numclients; i++) {
        if (clients[i].numcompte == numcompte) {
            accountIndex = i;
            break;
        }
    }
    if (accountIndex == -1) {
        printf("Compte non trouv�.\n");
        return;
    }
    printf("Solde actuel : %.2lf\n", clients[accountIndex].balance);
    printf("Type de transaction :\n");
    printf("1. D�p�t\n");
    printf("2. Retrait\n");
    printf("Entrez le num�ro du type de transaction : ");
    scanf("%d", &Typetransaction);
    switch (Typetransaction) {
        case 1:
            printf("Montant � d�poser : ");
            scanf("%lf", &amount);
            clients[accountIndex].balance += amount;
            printf("D�p�t effectu�. Nouveau solde : %.2lf\n", clients[accountIndex].balance);
            break;
        case 2:
            printf("Montant � retirer : ");
            scanf("%lf", &amount);
            if (amount > clients[accountIndex].balance) {
                printf("Solde insuffisant.\n");
            } else {
                clients[accountIndex].balance -= amount;
                printf("Retrait effectu�. Nouveau solde : %.2lf\n", clients[accountIndex].balance);
            }
            break;
        default:
            printf("Type de transaction invalide.\n");
            break;
    }
}
void supprimerCompte(Client *clients, int *numclients) {
    int accountToDelete;
    printf("Entrez le num�ro de compte � supprimer : ");
    scanf("%d", &accountToDelete);
    for (int i = 0; i < *numclients; i++) {
        if (clients[i].numcompte == accountToDelete) {
            for (int j = i; j < *numclients - 1; j++) {
                clients[j] = clients[j + 1];
            }
            (*numclients)--;
            printf("Compte %d supprim� avec succ�s.\n", accountToDelete);
            return;
        }
    }
    printf("Compte non trouv�.\n");
}
void afficherDetailsCompte(Client *clients, int numclients) {
    int accountToDisplay;
    printf("Entrez le num�ro de compte � afficher : ");
    scanf("%d", &accountToDisplay);
    for (int i = 0; i < numclients; i++) {
        if (clients[i].numcompte == accountToDisplay) {
            printf("\nD�tails du compte %d :\n", accountToDisplay);
            printf("Nom : %s\n", clients[i].nom);
            printf("Pr�nom : %s\n", clients[i].prenom);
            printf("Solde : %.2lf\n", clients[i].balance);
            return;
        }
    }
    printf("Compte non trouv�.\n");
}
void afficherListeClients(Client *clients, int numclients) {
    printf("\nListe des clients :\n");
    printf("------------------------------------------------\n");
    printf("| Num�ro de compte | Nom           | Pr�nom       | Solde  |\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < numclients; i++) {
        printf("| %-16d | %-13s | %-13s | %.2lf |\n", clients[i].numcompte, clients[i].nom,
               clients[i].prenom, clients[i].balance);
    }
    printf("------------------------------------------------\n");
}
int main() {
    Client clients[100];
    int numclients = 0;
    int choice;
    do {
        printf("\nMenu E-Bank :\n");
        printf("1. Cr�er un nouveau compte\n");
        printf("2. Mise � jour des informations d'un compte\n");
        printf("3. Afficher et g�rer les transactions bancaires\n");
        printf("4. Supprimer un compte existant\n");
        printf("5. Afficher les d�tails d'un compte existant\n");
        printf("6. Afficher la liste des clients\n");
        printf("7. Calculer les int�r�ts\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                creerCompte(clients, &numclients);
                break;
            case 2:
                mettreAJour(clients, numclients);
                break;
            case 3:
                gererTransactions(clients, numclients);
                break;
            case 4:
                supprimerCompte(clients, &numclients);
                break;
            case 5:
                afficherDetailsCompte(clients, numclients);
                break;
            case 6:
                afficherListeClients(clients, numclients);
                break;
            case 7:
                calculerInterets(clients, numclients);
                break;
            case 0:
                printf("Merci d'avoir utilis� E-Bank. Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
        }
    } while (choice != 0);
    return 0;
}
