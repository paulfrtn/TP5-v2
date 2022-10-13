#include "header.h"

/*

Tout ce programme à été réalisé grâce aux aides fournies par Mme.PALASI, l'aide pour le TP2 et l'aide pour le TP3.
+ le code fourni pour le TP2, qui à été notre base pour ce TP.

*/



int main()
{

    t_sommet* sommet;
    int choix =0;

    while(1) ///Creation d'un menu, on fait une boucle infinie
    {
        if(choix==-1)
        {
            exit(0);
        }
        if(choix==0) //Premier test pour le menu principale
        {
            system("cls");
            ///Différents choix dans le menu
            printf("1- Afficher le graphe.\n");
            printf("2- Algorithe Dijkstra. \n");
            printf("3- Quitter. \n");
            printf("Entrez votre choix :");
            scanf("%d",&choix);
        }
        if(choix==1) //Choix numero 1
        {
            system("cls");
            t_graphe* graphe=extraire_graphe(); //Extraction du graphe
            afficher_graphe(graphe); //affichage du graphe
            printf("Entrez 0 pour revenir au menu : ");
            scanf("%d",&choix);
            while(choix!=0)
            {
                system("cls");
                printf("Vous avez entre une valeur different 0:");
                scanf("%d",&choix);
            }
        }

        if(choix==2) //Choix numero 2
        {
            system("cls");
            t_graphe* graphe=extraire_graphe();
            int sommet_init=0;
            int sommet_final=0;

            printf("Entrez le sommet depuis lequel vous souhaitez commencer : ");
            scanf("%d",&sommet_init);
            while(sommet_init<0 || sommet_init>graphe->ordre)
            {
                printf("Le sommet selectionne n'existe pas, choisir entre 0 et %d:", graphe->ordre);
                scanf("%d",&sommet_init);
            }
            printf("Entrez le sommet sur lequel vous souhaitez terminer : ");
            scanf("%d",&sommet_final);
            while(sommet_final<0 || sommet_final> graphe->ordre)
            {
                printf("Le sommet selectionne n'existe pas, choisir entre 0 et %d:", graphe->ordre);
                scanf("%d",&sommet_final);
            }
            system("cls");


            //quitter le programme
            printf("Entrez 0 pour revenir au menu : ");
            scanf("%d",&choix);
            while(choix!=0)
            {
                system("cls");
                printf("Vous avez entre une valeur different 0:");
                scanf("%d",&choix);
            }
        }
        if(choix==3) //Choix numero 3
        {
            system("cls");
            choix=-1;
        }

    }
}

