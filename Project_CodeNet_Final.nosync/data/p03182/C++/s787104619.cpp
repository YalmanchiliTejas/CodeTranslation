#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_FEUILLE = (1 << 19);

struct Evenement{
    int temps, autre, type, nombre;

    bool operator<(Evenement autre) {
        return temps < autre.temps;
    }
};

struct Noeud{
    int debut, fin, maxInter, aAdd;
    int milieu() {return (fin-debut+1)/2;}
};

Noeud arbre[MAX_FEUILLE*2];

int nbFeuille;

void propage(int sommet) {
    arbre[sommet].maxInter += arbre[sommet].aAdd;
    if(sommet < nbFeuille) {
        arbre[sommet*2].aAdd += arbre[sommet].aAdd;
        arbre[sommet*2+1].aAdd += arbre[sommet].aAdd;
    }
    arbre[sommet].aAdd = 0;
}

void construireInter(int id) {
    if(id < nbFeuille) {
        arbre[id*2].debut = arbre[id].debut;
        arbre[id*2].fin = arbre[id].milieu() + arbre[id].debut - 1;
        arbre[id*2+1].debut = arbre[id*2].fin+1;
        arbre[id*2+1].fin = arbre[id].fin;
        construireInter(id*2);
        construireInter(id*2+1);
    }
}

bool estInclu(int d1, int f1, int d2, int f2) {
    return !(d2 > f1 || d1 > f2);
}

int reponseReq = -1e18;

void descendre(int id, int gauche, int droite, int nombre) {
    if(gauche > droite)
        return;
    if(gauche <= arbre[id].debut && droite >= arbre[id].fin) {
        arbre[id].aAdd += nombre;
        propage(id);

        reponseReq = max(reponseReq, arbre[id].maxInter);
    }
    else {
        propage(id);
        propage(id*2);
        propage(id*2+1);

        for(int i = 0; i < 2; i++) {
            if(estInclu(arbre[id*2+i].debut, arbre[id*2+i].fin, gauche, droite)) {
                descendre(id*2+i, gauche, droite, nombre);
            }
        }

        arbre[id].maxInter = max(arbre[id*2].maxInter, arbre[id*2+1].maxInter);
    }
}

int32_t main() {

    int taille, nbInter;
    cin >> taille >> nbInter;

    nbFeuille = (1 << ((int)ceil(log2(taille))));

    arbre[1].debut = 0;
    arbre[1].fin = nbFeuille-1;

    construireInter(1);

    vector<Evenement> event;

    int dp[taille] = {0};

    for(int i = 0; i < nbInter; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--;

        if(a == 0) {
            dp[0] += c;
        }

        event.push_back({a, b, 1, c});
        event.push_back({b, a, 0, c});
    }

    sort(event.begin(), event.end());

    int idEvent = 0;

    int curSomme = 0;

    while(idEvent < event.size() && event[idEvent].temps == 0) {
        if(event[idEvent].type == 1) {
            curSomme += event[idEvent].nombre;
        }
        else {
            curSomme -= event[idEvent].nombre;
        }
        idEvent++;
    }


    descendre(1, 0, 0, dp[0]);



    for(int bit = 1; bit < taille; bit++) {
        while(idEvent < nbInter*2 && event[idEvent].temps == bit) {
            if(event[idEvent].type == 1) {
                curSomme += event[idEvent].nombre;
                descendre(1, 0, bit-1, event[idEvent].nombre);
            }
            else {
                curSomme -= event[idEvent].nombre;
                descendre(1, 0, event[idEvent].autre-1, -event[idEvent].nombre);
            }
            idEvent++;
        }
        reponseReq = -1e18;
        descendre(1, 0, bit-1, 0);
        dp[bit] = max(reponseReq, curSomme);
        descendre(1, bit, bit, dp[bit]);

    }

    int total = 0;

    for(int i = 0; i < taille; i++) total = max(total, dp[i]);

    cout << total;

    return 0;
}
