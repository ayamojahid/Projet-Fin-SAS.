#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void MainMenu(void) {
      int choix;
    do {
        printf("\n=== SYSTEME D'ACHAT CLIENT ===\n");
        printf("1.  Gestion du profil client\n");
        printf("2.  Gestion du solde virtuel\n");
        printf("3.  Consultation des produits\n");
        printf("4.  Effectuer un achat\n");
        printf("5.  Mes statistiques\n");
        printf("0.  Quitter l'application\n");
        printf("Votre choix : ");
        if (scanf("%d", &choix) != 1) { 
        printf("Entrée invalide. On quitte.\n");
        return;
        }

        switch (choix) {
            case 1: menuProfil(); break;
            case 2: menuSolde(); break;
            case 3: menuProduits(); break;
            case 4: acheterProduit(); break;
            case 5: afficherStats(); break;
            case 0: printf("Au revoir 👋\n"); break;
            default: printf("Choix invalide. Reessayez.\n");
        }
    } while (choix != 0);
}

void menuProfil(void) {
    int choix;
    do {
        printf("\n--- GESTION DU PROFIL CLIENT ---\n");
        printf("1. Creer un profil\n");
        printf("2. Consulter le profil\n");
        printf("3. Modifier le profil\n");
        printf("0. Retour\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: creerProfil(); break;
            case 2: consulterProfil(); break;
            case 3: modifierProfil(); break;
            case 0: break;
            default: printf("Choix invalide \n");
        }
    } while (choix != 0);
}

void menuProduits(void) {
    int choix;
    do {
        printf("\n--- CATALOGUE DES PRODUITS ---\n");
        printf("1. Afficher tous les produits\n");
        printf("2. Rechercher un produit par nom\n");
        printf("3. Rechercher un produit par categorie\n");
        printf("4. Trier les produits par prix\n");
        printf("5. Trier les produits par nom\n");
        printf("6. Details d’un produit\n");
        printf("0. Retour\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        
         switch (choix) {
            case 1: afficherCatalogue(); break;
            case 2: rechercherProduitNom(); break;
            case 3: rechercherProduitCategorie(); break;
            case 4: trierParPrix(); break;
            case 5: trierParNom(); break;
            case 6: detailsProduit(); break;
            case 0: break;
            default: printf("Choix invalide !\n");
        } 
    } while (choix != 0);
}

    int nbClients=0;
    Client cl[100];

    void creerProfil (void) {
    printf("\n=== CREATION DE PROFIL ===\n");
    printf("Nom : ");
    scanf(" %s" ,cl[0].nom );
    printf("Prenom : ");
    scanf("%s" ,cl[0].prenom);
    sprintf(cl[0].email , "%s.%s@gmail.com" ,cl[0].nom,cl[0].prenom);
    cl[0].idClient = 1;
    cl[0].solde=0;
    nbClients=1;
    printf(" Profil cree avec succes \n");
    }
    
    void consulterProfil (void) {
    if (nbClients==0) {
    printf("Aucun profil a cree");
    return;
    } 
    printf("\n=== PROFIL ===\n");
    printf("ID: %d\n" , cl[0].idClient);
    printf("Le Nom: %s\n", cl[0].nom);
    printf("Le Prenom: %s\n" , cl[0].prenom);
    printf("L'Email: %s\n" , cl[0].email);
    printf("Le Solde: %.2f dh " , cl[0].solde);
    }

    void modifierProfil(void)  {
    if(nbClients==0) {
    printf(" Aucun profil a modifier.\n");
    return;
    }
     printf("\n=== MODIFICATION DE PROFIL ===\n");
     printf("Le nouveau nom : ");
     scanf("%s" ,cl[0].nom );
     printf("Le nouveau prenom : ");
     scanf("%s" , cl[0].prenom);
     sprintf(cl[0].email, "%s.%s@gmail.com" , cl[0].nom,cl[0].prenom);
    }
  
void menuSolde(void){
    int choix;
    do {
         printf("\n--- GESTION DU SOLDE VIRTUEL ---\n");
         printf("1. Deposer de l'argent \n");
         printf("2. Consulter le solde\n");
         printf("0. Retour\n");
         printf("Votre choix : ");
         scanf("%d", &choix);
         switch (choix)
         {
         case 1: deposerArgent(); break;
         case 2: consulterSolde(); break;
         case 0: break;
         default: printf("Choix invalide \n"); 
         }
         }while (choix !=0);
   
    
}     
void deposerArgent(void){
    if (nbClients==0) {
        printf("Aucun profile a cree \n ");
        return;
    }
    float montant;
    printf("Veuillez entrer le montant a deposer : ");
    scanf("%f" , &montant);

    if(montant>0) {
        cl[0].solde=cl[0].solde+montant;
        printf("le depot reussi. Nouveau solde est : %.2f dh\n", cl[0].solde);
    } else {
        printf(" Montant est invalide \n");
    }
}

void consulterSolde(void) {
if(nbClients==0) {
    printf("Aucun profile a cree");
    return;
} printf("\n Votre solde actuel est : %.2f dh\n", cl[0].solde);

}

int nbProduis;
Produit prod[10] = {
    {1, "Phone", "Elec", 20.50, 60, "Un telephone basique"},
    {2, "PC", "Elec", 799.00, 10, "Un ordinateur portable performant"},
    {3, "Clavier", "Accessoire", 45.00, 12, "Un clavier mecanique"},
    {4, "Souris", "Accessoire", 25.00, 20, "Souris optique sans fil"},
    {5, "Casque Audio", "Accessoire", 89.00, 15, "Casque sans fil Bluetooth"},
    {6, "Tablette", "Elec", 299.00, 8, "Tablette tactile Android"},
    {7, "Imprimante", "Elec", 450.00, 5, "Imprimante multifonction"},
    {8, "Television", "Elec", 1200.00, 4, "Television 42 pouces HD"},
    {9, "Disque Dur", "Accessoire", 350.00, 7, "Disque dur externe 1 To"},
    {10, "USB", "Accessoire", 15.00, 30, "Cle USB 32 Go"}
};



void afficherCatalogue(void) {    
    printf("\n=== CATALOGUE DES PRODUITS ===\n\n");
    printf("ID | Nom | Categorie | Prix | Stock | Description\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < 10; i++) {
        printf("%d | %s | %s | %.2f dh | %d | %s\n",
            prod[i].idProduit,
            prod[i].nom,
            prod[i].caterogie,
            prod[i].prix,
            prod[i].stock,
            prod[i].description
        );
    }
}

void rechercherProduitNom() {
char recherche[30];
int trouve=0;
 printf("\n=== RECHERCHE PRODUIT PAR NOM ===\n");
 printf("Entrez le nom du produit a rechercher : ");
scanf("%s", recherche);   
 printf("%s" ,recherche);
 for(int i=0; i<10 ; i++) {
    if (strcasecmp(prod[i].nom, recherche) == 0) {
    printf("\nle produit est  trouve \n");
    printf("ID: %d\nNom: %s\nCategorie: %s\nPrix: %.2f dh\nStock: %d\nDescription: %s\n" ,
        prod[i].idProduit,
        prod[i].nom,
        prod[i].caterogie,
        prod[i].prix,
        prod[i].stock,
        prod[i].description
    );
    trouve=1;
    break;
 }
}   if (!trouve) 
        printf("\nProduit non trouve \n");
     }


     void rechercherProduitCategorie() {
    char recherche[30];
    int trouve = 0;

    printf("\n=== RECHERCHE PRODUIT PAR CATEGORIE ===\n");
    printf("Entrez la categorie a rechercher : ");
    scanf("%s", recherche);   // lire catégorie recherchée

    for (int i = 0; i < 10; i++) {
        if (strcmp(prod[i].caterogie, recherche) == 0) {
            printf("\nProduit trouve !\n");
            printf("ID: %d\nNom: %s\nCategorie: %s\nPrix: %.2f dh\nStock: %d\nDescription: %s\n",
                prod[i].idProduit,
                prod[i].nom,
                prod[i].caterogie,   
                prod[i].prix,
                prod[i].stock,
                prod[i].description
            );
            trouve = 1;
        }
    }

    if (!trouve)
        printf("\nAucun produit trouve dans cette categorie.\n");
}


void trierParPrix() {}
void trierParNom() {}
void detailsProduit() {}
void acheterProduit(void) {}
void afficherStats(void) {}
