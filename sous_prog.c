#include "header.h"

/* affichage des successeurs du sommet num*/
void afficher_successeurs(t_sommet** sommet, int num)
{

    printf(" sommet %d :\n",num);

    t_arc* arc=sommet[num]->arc;

    while(arc!=NULL)
    {
        printf("\t successeur: %d | poids : %d  \n",arc->sommet,arc->poids);
        arc=arc->arc_suivant;
    }

}

// Ajouter l'ar te entre les sommets s1 et s2 du graphe
t_sommet** CreerArete(t_sommet** sommet,int s1,int s2, int poids)
{
    if(sommet[s1]->arc==NULL)
    {
        t_arc* Newarc=(t_arc*)malloc(sizeof(t_arc));
        Newarc->sommet=s2;
        Newarc->poids=poids;
        Newarc->arc_suivant=NULL;
        sommet[s1]->arc=Newarc;
        return sommet;
    }
    else
    {
        t_arc* temp=sommet[s1]->arc;
        while( !(temp->arc_suivant==NULL))
        {
            temp=temp->arc_suivant;
        }
        t_arc* Newarc=(t_arc*)malloc(sizeof(t_arc));
        Newarc->sommet=s2;
        Newarc->poids=poids;
        Newarc->arc_suivant=NULL;

        temp->arc_suivant=Newarc;
        return sommet;
    }
}

// cr er le graphe
t_graphe* creation_graphe(int ordre)
{
    t_graphe * Newgraphe=(t_graphe*)malloc(sizeof(t_graphe));
    Newgraphe->pSommet = (t_sommet**)malloc(ordre*sizeof(t_sommet*));

    for(int i=0; i<ordre; i++)
    {
        Newgraphe->pSommet[i]=(t_sommet*)malloc(sizeof(t_sommet));
        Newgraphe->pSommet[i]->valeur=i;
        Newgraphe->pSommet[i]->marquage=0;
        Newgraphe->pSommet[i]->degre=0;
        Newgraphe->pSommet[i]->predec=-1;
        Newgraphe->pSommet[i]->arc=NULL;
    }
    return Newgraphe;
}


/* La construction du r seau peut se faire   partir d'un fichier dont le nom est pass  en param tre
Le fichier contient : ordre, taille,orientation (0 ou 1)et liste des arcs */
t_graphe* extraire_graphe()
{
    t_graphe* graphe;
    FILE * ifs = fopen("graphe1_TP3.txt","r");
    int taille, ordre, s1, s2, poids;

    if (!ifs)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    fscanf(ifs,"%d",&ordre);

    graphe=creation_graphe(ordre); // cr er le graphe d'ordre sommets

    fscanf(ifs,"%d",&taille);
    graphe->ordre=ordre;

    // cr er les ar tes du graphe
    for (int i=0; i<taille; ++i)
    {
        fscanf(ifs,"   %d %d %d",&s1,&s2,&poids);
        graphe->pSommet=CreerArete(graphe->pSommet, s1, s2,poids);

        //if(!orientation)
        graphe->pSommet=CreerArete(graphe->pSommet, s2, s1, poids);
    }

    return graphe;
}

/*affichage du graphe avec les successeurs de chaque sommet */
void afficher_graphe(t_graphe* graphe)
{
    printf("graphe\n");


    printf("ordre = %d\n",graphe->ordre);

    printf("listes d'adjacence :\n");

    for (int i=0; i<graphe->ordre; i++)
    {
        afficher_successeurs(graphe->pSommet, i);
        printf("\n");
    }

}

/*
Ce sous programme permet de savoir si tout les sommets ont été visités
Le principe est de vérifier les sommets marqués, lorsqu'un sommet est marque on ajoute 1 dans un compteur
Lorsque ce compteur est égal aux nombre de sommets du graphe, alors ça signifie que tout les sommets ont été visités
*/
int sommet_all_visited(t_graphe* graphe)
{
    int total=0;
    for(int i=0; i<graphe->ordre; i++)
    {
        if(graphe->pSommet[i]->marquage==1)
        {
            total+=1;
        }
    }
    if(total==graphe->ordre)
    {
        return 1;
    }
}

//ici on recherche le minimum
int minimum(t_graphe* graphe)
{
    int minimum = 5000;  //Ici minimum vaut la valeur de la distance "infinie"
    int min =-1;  // On initialise un entier min à -1, pour le renvoyer au programme appelant et l'utiliser dans dijkstra

    for(int i=0; i<graphe->ordre; i++)
    {
        // On vérifie que le sommet i n'est pas marque et que sa distance n'est pas infinie
        if( ( graphe->pSommet[i]->marquage != 1 ) && ( graphe->pSommet[i]->dist < minimum ))
        {
            minimum = graphe->pSommet[i]->dist; // On associe alors à minimum la distance du sommet i
            min=i;                              // Ainsi la variable renvoyée prend la valeur de i
        }
    }
    return min; //On retourne min au programme appelant
}

void kruskal()
{

}

void prim(t_graphe* graphe)
{
}



