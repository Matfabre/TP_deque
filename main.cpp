#include <iostream>
#include "Deque.hpp"
#include "algo.hpp"
using namespace std;

int main()
{
    Carte c1{20,20};
    char c;
    do
    {
        c1.deplacer();
        std::cout << "voulez vous quitter ? Oui: y" << std::endl;
        std::cin >> c;
    }while (c != 'y');
    return 0;
}

/*
1-Comprendre l'utilisation du deque et ses sp�cificit�s
2-Parvenir � creer un tableau bidimensionnel de deque
3-Etablir un tableau de deque (TDD) de points (x;y)
4-Rendre possible l'ajour de points dans les quatre directions possibles
5-Prendre en compte les cas sp�cifiques (haut-gauche, bas-droit par exemple)
6-Permettre un affichage du tableau en console
7-Algorithme de recherche de chemin simple dans une carte d�finie en TDD de points (x;y;passable) passables et impassables
8-Algorithme de recherche de chemin complexe avec pond�ration de vitesse de progression
9-Facultatif : Affichage via SFML
10-Generation de carte semi-realiste avec proc�duralit�
11-V�rification du fonctionnement dans une carte de grande taille (>500*500)
12-Optimisation finale du code
*/
