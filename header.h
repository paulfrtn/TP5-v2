//
// Created by paula on 10/10/2022.
//

#ifndef TP5_HEADER_H
#define TP5_HEADER_H


///-----------------------------------------------------Librairies

#include <stdio.h>
#include <stdlib.h>


///-------------------------------------------------------Graphe

typedef struct arc
{
    int sommet;
    int valeur;
    int poids;
    struct _arc* arc_suivant;
}t_arc;

typedef struct sommet
{
    t_arc* arc;
    int valeur;
    int marquage;
    int predec;
    int dist;
    int degre;
}t_sommet;

typedef struct Graphe
{
    int taille;
    int ordre;
    t_sommet** pSommet;
}t_graphe;


///-----------------------------------------------------Prototypes

void afficher_successeurs(t_sommet** sommet, int num);
t_sommet** CreerArete(t_sommet** sommet,int s1,int s2,int poids);
t_graphe* creation_graphe(int ordre);
t_graphe* extraire_graphe();
void afficher_graphe(t_graphe* graphe);
int sommet_all_visited(t_graphe* graphe);
int minimum(t_graphe* graphe);
void dijkstra(t_graphe* graphe, int sommet_init, int sommet_final);
void kruskal();
void prim();

#endif //TP5_HEADER_H
