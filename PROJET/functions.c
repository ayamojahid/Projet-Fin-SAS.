#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void MainMenu(void)
{
    int choix;
    creerProfil();
    do
    {
        printf("\n SYSTEME D'ACHAT CLIENT \n");
        printf("1.  gestion du profil client\n");
        printf("2.  gestion du solde virtuel\n");
        printf("3.  gestion des produits\n");
        printf("4.  achat des produits\n");
        printf("5. consulter l'historique des achats\n");
        printf("0.  quitter l'application\n");
        printf("votre choix : ");
        if (scanf("%d", &choix) != 1)
        {
            printf("entree n'est valide \n");
            while (getchar() != '\n'); 
            choix = -1;
        }

        switch (choix)
        {
        case 1:
            menuProfil();
            break;
        case 2:
            menuSolde();
            break;
        case 3:
            menuProduits();
            break;
        case 4:
            acheterProduit();
            break;
        case 5:
         historiqueAchats();
          break;

            break;
        case 0:
            printf("vous avez quitte l'application\n");
            break;
        default:
            printf("Choix n'est pas valide Reessayez.\n");
        }
    } while (choix != 0);
}

void menuProfil(void)
{
    int choix;
    do
    {
        printf("\n GESTION DU PROFIL CLIENT \n");
        printf("1. Afficher le profil\n");
        printf("2. maodifier le profil\n");
        printf("0. retour\n");
        printf("votre choix : ");
      if (scanf("%d", &choix) != 1) {
    printf("entree non valide, reessayez.\n");
    while (getchar() != '\n'); 
    choix = -1;
}


        switch (choix)
        {
        case 1:
            AfficherProfil();
            break;
        case 2:
            modifierProfil();
            break;
        case 0:
            break;
        default:
            printf("choix n'est pas valide \n");
        }
    } while (choix != 0);
}

void menuProduits(void)
{
    int choix;
    do
    {
        printf("\n MENU PRODUITS \n");
        printf("1. afficher tous les produits\n");
        printf("2. rechercher un produit par nom\n");
        printf("3. rechercher un produit par categorie\n");
        printf("4. trier les produits par prix croissant\n");
        printf("5. trier les produits par prix decroissant\n");
        printf("6. trier les produits par nom\n");
        printf("7. details d'un produit\n");
        printf("0. retour\n");
        printf("votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            afficherCatalogue();
            break;
        case 2:
            rechercherProduitNom();
            break;
        case 3:
            rechercherProduitCategorie();
            break;
        case 4:
            trierParPrixCroissant();
            break;
        case 5:
            trierParPrixDecroissant();
            break;
        case 6:
            trierParNom();
            break;
        case 7:
            detailsProduit();
            break;
        case 0:
            break;
        default:
            printf("votre choix n'est pas valide \n");
        }
    } while (choix != 0);
}

Client cl;

void creerProfil(void)
{
    printf("\n CREATION DE PROFIL \n");
    printf("veuillez entrer votre nom : ");
    scanf(" %[^\n]", cl.nom);
    printf("veullez entrer votre prenom : ");
    scanf(" %[^\n]", cl.prenom);
    sprintf(cl.email, "%s.%s@gmail.com", cl.nom, cl.prenom);
    cl.idClient = 1;
    cl.solde = 0;
    printf(" profil cree avec succes \n");
}

void AfficherProfil(void)
{

    printf("\n PROFIL \n");
    printf("Id: %d\n", cl.idClient);
    printf("le nom: %s\n", cl.nom);
    printf("le prenom: %s\n", cl.prenom);
    printf("l'email: %s\n", cl.email);
    printf("le solde: %.2f dh \n", cl.solde);
    printf("\n");
}

void modifierProfil(void)
{

    printf("\n MODIFICATION DE PROFIL \n");
    printf("le nouveau nom : ");
    scanf(" %[^\n]", cl.nom);
    printf("le nouveau prenom : ");
    scanf(" %[^\n]", cl.prenom);
    sprintf(cl.email, "%s.%s@gmail.com", cl.nom, cl.prenom);
}

void menuSolde(void)
{
    int choix;
    do
    {
        printf("\n GESTION DU SOLDE VIRTUEL \n");
        printf("1. deposer de l'argent \n");
        printf("2. consulter le solde\n");
        printf("0. retour\n");
        printf("votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            deposerArgent();
            break;
        case 2:
            consulterSolde();
            break;
        case 0:
            break;
        default:
            printf("choix n'est pas valide \n");
        }
    } while (choix != 0);
}
void deposerArgent(void)
{
    float montant;
    printf("veuillez entrer le montant a deposer : ");
    scanf("%f", &montant);

    if (montant > 0)
    {
        cl.solde = cl.solde + montant;
        printf("le depot reussi le nouveau solde est : %.2f dh\n", cl.solde);
    }
    else
    {
        printf(" montant n'est pas valide  \n");
    }
}

void consulterSolde(void)
{
    printf("\n votre solde actuel est : %.2f dh\n", cl.solde);
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
    {10, "USB", "Accessoire", 15.00, 30, "Cle USB 32 Go"}};

void afficherCatalogue(void)
{
    printf("\n CATALOGUE DE LES PRODUITS \n\n");
    printf("ID | nom   | prix   | stock\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d | %s | %.2f dh | %d\n",
   prod[i].idProduit, prod[i].nom, prod[i].prix, prod[i].stock);
    }
}

void detailsProduit()
{
    int choixid;
    int trouve = 0;
    printf("veuillez entrer l'id a chercher : ");
    scanf("%d", &choixid);
    for (int i = 0; i < 10; i++)
    {
        if (choixid == prod[i].idProduit)
        {
            printf("\n DETAIL DE PRODUIT \n\n");
            printf("Id          : %d\n", prod[i].idProduit);
            printf("nom         : %s\n", prod[i].nom);
            printf("categorie   : %s\n", prod[i].caterogie);
            printf("prix        : %.2f dh\n", prod[i].prix);
            printf("stock       : %d\n", prod[i].stock);
            printf("description : %s\n", prod[i].description);
            trouve = 1;
            break;
        }
    }
    if (!trouve)
    {
        printf("aucun produit avec cette id :");
    }
}

void rechercherProduitNom(void)
{
    char rechercheID[30];
    int trouve = 0;
    printf("\n RECHERCHE PRODUIT PAR NOM \n");
    printf("entrez le nom du produit a rechercher :  ");
    scanf(" %[^\n]", rechercheID);
    printf("%s", rechercheID);
    for (int i = 0; i < 10; i++)
    {
        if (strcasecmp(prod[i].nom, rechercheID) == 0)
        {
            printf("\n      le produit est  trouve \n");
            printf("ID: %d\nnom: %s\ncategorie: %s\nprix: %.2f dh\nstock: %d\ndescription: %s\n",
                   prod[i].idProduit, prod[i].nom, prod[i].caterogie, prod[i].prix, prod[i].stock, prod[i].description);
            trouve = 1;
            break;
        }
    }
    if (!trouve)
        printf("\n aucun produit avec ce nom \n");
}

void rechercherProduitCategorie(void)
{
    char recherche[30];
    int trouve = 0;

    printf("\n RECHERCHE PRODUIT PAR CATEGORIE \n");
    printf("Entrez la categorie a rechercher : ");
    scanf(" %[^\n]", recherche);

    for (int i = 0; i < 10; i++)
    {
        if (strcasecmp(prod[i].caterogie, recherche) == 0)
        {
            printf("\n produit est trouve \n");
            printf("ID: %d\nnom: %s\ncategorie: %s\nprix: %.2f dh\nstock: %d\ndescription: %s\n",
                   prod[i].idProduit, prod[i].nom, prod[i].caterogie, prod[i].prix, prod[i].stock, prod[i].description);
            trouve = 1;
        }
    }

    if (!trouve)
        printf("\n Aucun produit trouve dans cette categorie \n");
}

void trierParPrixDecroissant()
{
    Produit temps;
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - 1 - i; j++)
        {
            if (prod[j].prix < prod[j + 1].prix)
            {
                temps = prod[j];
                prod[j] = prod[j + 1];
                prod[j + 1] = temps;
            }
        }
    }
    printf("\n PRODUITS TRIES PAR PRIX DECROISSANT \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d | %s | %d | %.2f dh \n",
     prod[i].idProduit, prod[i].nom, prod[i].stock, prod[i].prix);
    }
}

void trierParPrixCroissant(void)
{
    Produit temps;
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - 1 - i; j++)
        {
            if (prod[j].prix > prod[j + 1].prix)
            {
                temps = prod[j];
                prod[j] = prod[j + 1];
                prod[j + 1] = temps;
            }
        }
    }

    printf("\n PRODUITS TRIES PAR PRIX CROISSANT \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d | %s | %d | %.2f dh \n",
               prod[i].idProduit, prod[i].nom, prod[i].stock, prod[i].prix);
    }
}

void trierParNom(void)
{
    Produit temp;
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (strcasecmp(prod[j].nom, prod[j + 1].nom) > 0)
            {
                temp = prod[j];
                prod[j] = prod[j + 1];
                prod[j + 1] = temp;
            }
        }
    }

    printf("\n PRODUITS TRIES PAR NOM \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d | %s | %s | %.2f dh | Stock: %d\n",
               prod[i].idProduit, prod[i].nom, prod[i].caterogie, prod[i].prix, prod[i].stock);
    }
} 



char historique[1000] = "";

void acheterProduit(void)
{
    int achat;
    int quantiteProduit;
    printf("\n ACHAT PRODUIT \n");
    printf("catalogue disponible \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d | %s | %.2f dh | stock: %d\n",
        prod[i].idProduit, prod[i].nom, prod[i].prix, prod[i].stock);
    }

    printf("veuillez entrer id de produit que vous voulez acheter  : ");
    scanf("%d", &achat);
    int index = -1;
for (int i = 0; i < 10; i++) {
    if (prod[i].idProduit == achat) {
        index = i;
        break;
    }
}

for (int i = 0; i < 10; i++) {
    if (prod[i].idProduit == achat) {
        index = i;
        break;
    }
}
if (index == -1) {
    printf("désolé ce produit ne se trouve pas\n");
    return;
}

    printf("veuillez entrer la quantite d'achat : ");
    scanf("%d", &quantiteProduit);

    if (quantiteProduit <= 0)
    {
        printf("quantite nest pas valide");
        return;
    }

  if (prod[index].stock < quantiteProduit)
{ 
    printf("desole ce stock ne se trouve pas entrer autre : \n ");
    return;
}

 float prix = prod[index].prix * quantiteProduit;
if (cl.solde < prix) 
{
    printf("\n desole le solde est insuffisant");
    return;
}
cl.solde = cl.solde - prix;
prod[index].stock = prod[index].stock - quantiteProduit;

printf(" \n l'achat est reussi \n");
printf("\nvous avez achete  %s de prix %.2f dh\n", prod[index].nom, prod[index].prix);
printf("\nvotre nouveau solde est : %.2f dh\n", cl.solde);
printf("\nstock restee est : %d\n", prod[index].stock);

char ligne[200];
sprintf(ligne, "%d  %s  %.2f dh\n", quantiteProduit, prod[index].nom, prix);
strcat(historique, ligne);


}

void historiqueAchats(void) {
    printf("\n  HISTORIQUE DES ACHATS  \n");
    if (historique[0] == '\0') {
        printf("aucun achat effectue.\n");
    } else {
        printf("%s", historique); 
    }
}