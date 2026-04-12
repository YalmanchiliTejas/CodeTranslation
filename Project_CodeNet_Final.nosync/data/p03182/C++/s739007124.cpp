#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = (1<<18);
struct Intervalle
{
	int maximum , ajout;
};

struct Event
{
	int moment , debut , fin , valeur;
	bool operator < (const Event & autre) const
	{
		return moment < autre.moment;
	}
};

int taille;
Intervalle arbre[MAXN * 2];
void update(int noeud)
{
	arbre[noeud].maximum += arbre[noeud].ajout;
	if (noeud < MAXN)
	{
		arbre[noeud * 2].ajout += arbre[noeud].ajout;
		arbre[noeud * 2 + 1].ajout += arbre[noeud].ajout;
	}
	arbre[noeud].ajout = 0;
}

void merge(int noeud)
{
	arbre[noeud].maximum = max(arbre[noeud * 2].maximum , arbre[noeud * 2  + 1].maximum);
}

void ajouter(int noeud , int debut , int fin , int debutCible , int finCible , int ajout)
{
	//cout<<debut<<" "<<fin<<" "<<noeud<<" "<<debutCible<<" "<<finCible<<endl;
	update(noeud);
	if (debutCible <= debut && fin <= finCible)
	{
		arbre[noeud].ajout += ajout;
		update(noeud);
	}
	else if (!(fin < debutCible || debut > finCible))
	{
		ajouter(noeud * 2 , debut , (debut + fin) / 2 , debutCible , finCible , ajout);
		ajouter(noeud * 2 + 1 , (debut + fin) / 2 + 1 , fin , debutCible , finCible , ajout);
		merge(noeud);
	}
}

int recupeMax(int noeud , int debut , int fin , int debutCible , int finCible)
{
	update(noeud);
	if (debutCible <= debut && fin <= finCible)
	{
		return arbre[noeud].maximum;
	}
	else if (!(fin < debutCible || debut > finCible))
	{
		int g = recupeMax(noeud * 2 , debut , (debut + fin) / 2 , debutCible , finCible);
		int d = recupeMax(noeud * 2 + 1 , (debut + fin) / 2 + 1 , fin , debutCible , finCible);
		merge(noeud);
		return max(g , d);
	}
	else
	{
		return -1e18;
	}
}

int dp[MAXN];

int32_t main()
{
	int nbSegments;
	cin >> taille >> nbSegments;
	Event events[nbSegments * 2];
	for (int i = 0 ; i < nbSegments ; i++)
	{
		int debut , fin , v;
		cin >> debut >> fin >> v;
		events[i * 2] = {debut , debut , fin , -v};
		events[i * 2 + 1] = {fin + 1 , debut , fin , v};
	}
	int nbEvents = nbSegments * 2;
	sort(events , events + nbEvents);
	int totalActu = 0;
	int in = 0;
	int leMax = 0;
	for (int i = 1 ; i <= taille ; i++)
	{
		while (in < nbEvents && events[in].moment == i)
		{
			totalActu -= events[in].valeur;
			ajouter(1 , 0 , MAXN - 1 , events[in].debut , events[in].fin , events[in].valeur);
			in++;
		}
		dp[i] = recupeMax(1 , 0 , MAXN - 1 ,  0 , i - 1) + totalActu;
		ajouter(1 , 0 , MAXN - 1 , i , i , dp[i]);
		leMax = max(leMax , dp[i]);
	}
	cout<<leMax<<endl;

}