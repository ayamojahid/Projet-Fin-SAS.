#ifndef HEADER_H
#define HEADER_H

typedef struct 
{
    int idClient;
    char nom[40];
    char prenom[40];
    char email[30];
    float solde;
} Client;


typedef struct {
    int idProduit;
    char nom[30];
    char caterogie[30];
    float prix;
    int stock;
    char description[100];

}Produit;

typedef struct {
    char nomProduit[30];
    int quantiteHistorique;
    float prixTotal;
} Achat;

void MainMenu(void);

void menuProfil(void); 

void menuSolde(void);  

void menuProduits(void); 

void creerProfil(void); 

void AfficherProfil(void );

void modifierProfil(void); 

void deposerArgent(void);

void consulterSolde(void);

void acheterProduit(void);


void rechercherProduitNom(void);

void rechercherProduitCategorie(void);

void trierParPrixDecroissant(void);

void trierParPrixCroissant(void);

void trierParNom(void);

void detailsProduit(void);

void afficherCatalogue(void);

void statistiques(void);

#endif