#include <deque>
#include <iostream>
#include <windows.h>

typedef std::deque<int> intdeq;
//Ajoute un 1 aléatoirement lors de la création de la carte
int random ()
{
    double val = (double)rand() / RAND_MAX;
    int random;
    if (val < 0.15)       //  15%
        random = 1;
    else random = 0;
    return random;
}
class Carte
{
private:
    int init_x;
    int init_y;
    std::deque<intdeq> tabGlobal;
    void initCarte(int x, int y)
    {
        for(int i = 0; i<x; i++)
        {
            intdeq tableau;
            for(int j = 0; j<y; j++)
            {
                tableau.push_back(random());
            }
            tabGlobal.push_back(tableau);
        }
        afficher(tabGlobal);
    }
    void afficher(std::deque<intdeq> tab)
    {
        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        for( int i=0; i< (int)tab.size(); i++)
        {
            for( int j = 0; j<  (int)tab.at(i).size(); j++)
            {
                SetConsoleTextAttribute(hConsole, 10); //vert
                std::cout << tab.at(i).at(j);
            }
            std::cout << '\n';
        }
        SetConsoleTextAttribute(hConsole, 9); // bleu
        //SetConsoleTextAttribute(hConsole, 12); // rouge
        std::cout << "\nChoisir des coordonnees (x:y)" << std::endl;
    }
public:

    Carte(int m_x,int m_y)
    {
        init_x = m_x;
        init_y = m_y;
        initCarte(init_x,init_y);
    }
    ~Carte(){}
    std::deque<intdeq> getCarte()
    {
        return tabGlobal;
    }
    void setCarte(std::deque<intdeq> _tab)
    {
        tabGlobal = _tab;
    }
    // Ajouter un 3 sur l'emplacement voulu, si il n'existe pas, la carte est etendue.
    void deplacer()
    {
        int x, y;
        std::cout << "x= ";
        std:: cin >> x;
        std::cout << x << " ; y= ";
        std:: cin >> y;
        std::cout << y << std::endl;
        std::deque<intdeq> tab = getCarte();
        int taille = tab.size();
        if(x> taille || y > taille)
        {
            if(x > taille)
            {
                for(int j =0  ; j <x-taille; j++)
                {
                    intdeq tableau;
                    for(int i =0  ; i <taille; i++)
                    {
                        tableau.push_back(random());
                    }
                    tab.emplace_back(tableau);
                }
            }
            if(y > taille && x > taille)
            {
                for(int i = 0 ; i <y; i++)
                {
                    for(int j = 0 ; j <x-taille; j++)
                    {
                        tab.at(i).push_back(random());
                    }
                }
            }
            if(y > taille && x <= taille)
            {
                for(int i = 0 ; i <y-taille; i++)
                {
                    for(int j = 0 ; j <y-taille; j++)
                    {
                        tab.at(j).push_back(random());
                    }
                }
            }
        }
        tab[x-1][y-1]=3;
        system("CLS");
        setCarte(tab);
        afficher(tab);
    }

};

