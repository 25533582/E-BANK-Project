# E-BANK-Project

Projet E-Bank Preview
Ce projet, intitulé E-Bank, est une application de gestion bancaire implémentée en langage C. L'objectif principal de ce programme est de permettre la création, la mise à jour, la gestion des transactions, la suppression, l'affichage des détails, et l'affichage de la liste des clients d'une banque virtuelle. Les fonctionnalités principales du programme sont les suivantes :

Structures de données :
Transaction :

•	Attributs :

•	type[20] : une chaîne de caractères représentant le type de transaction (par exemple, "Dépôt", "Retrait", "Interest").

•	amount : un nombre à virgule flottante représentant le montant de la transaction.

Client :

•	Attributs :

•	numcompte : un entier représentant le numéro de compte du client.

•	nom[50] : une chaîne de caractères représentant le nom du client.

•	prenom[50] : une chaîne de caractères représentant le prénom du client.

•	balance : un nombre à virgule flottante représentant le solde du compte.

•	transactions[100] : un tableau de transactions permettant de stocker l'historique des transactions du client.

•	transactionCount : un entier représentant le nombre de transactions effectuées par le client.


Fonctions :

creerCompte(Client *clients, int *numclients) :

•	Crée un nouveau compte client en récupérant les informations du client depuis l'entrée utilisateur.

•	Incrémente le nombre total de clients.


mettreAJour(Client *clients, int numclients) :

•	Met à jour le solde d'un compte en fonction du numéro de compte fourni par l'utilisateur.

calculerInterets(Client *clients, int numclients) :

•	Calcule les intérêts (5% du solde) pour un compte spécifique.

•	Enregistre la transaction "Interest" dans l'historique du client.

gererTransactions(Client *clients, int numclients) :

•	Permet à l'utilisateur de déposer ou de retirer de l'argent d'un compte spécifique.

•	Met à jour le solde du compte en conséquence.

•	Gère les cas d'insuffisance de fonds.

supprimerCompte(Client *clients, int *numclients) :

•	Supprime un compte client en fonction du numéro de compte fourni par l'utilisateur.

•	Réorganise les autres comptes pour maintenir une liste continue.

afficherDetailsCompte(Client *clients, int numclients) :

•	Affiche les détails d'un compte spécifique, y compris le nom, le prénom et le solde.

afficherListeClients(Client *clients, int numclients) :

•	Affiche une liste tabulaire de tous les clients avec leur numéro de compte, nom, prénom et solde.

main() :

•	Point d'entrée du programme.

•	Affiche un menu interactif permettant à l'utilisateur d'effectuer diverses opérations bancaires.

•	Boucle jusqu'à ce que l'utilisateur choisisse de quitter le programme.

Utilisation :

L'utilisateur peut interagir avec le programme en sélectionnant différentes options du menu, telles que la création de nouveaux comptes, la mise à jour des informations, la gestion des transactions, la 
suppression de comptes existants, l'affichage des détails d'un compte et la visualisation de la liste des clients.

Limitations :

•	Le programme peut gérer jusqu'à 100 clients.


•	Les transactions sont limitées à un maximum de 100 par client.

Ce projet offre une base solide pour une application de gestion bancaire simple mais fonctionnelle. Des améliorations futures pourraient inclure la gestion des erreurs, la persistance des données, une interface utilisateur plus conviviale, et l'extension des fonctionnalités pour répondre à des besoins bancaires plus avancés.

