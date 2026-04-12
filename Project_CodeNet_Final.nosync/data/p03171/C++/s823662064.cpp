#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 3000;
int N;
int meilleur[MAXN][MAXN];

int somme[MAXN + 1];
int recursion(int gauche , int droite)
{
	if (gauche > droite) return 0;
	else if (meilleur[gauche][droite] != 0)
	{
		return meilleur[gauche][droite];
	}
	meilleur[gauche][droite] = somme[droite + 1] - somme[gauche] - min(recursion(gauche + 1 ,droite) , recursion(gauche , droite - 1));
	return meilleur[gauche][droite];
}
int32_t main()
{
	cin >> N;
	for (int i = 1 ; i <= N ; i++)
	{
		int a;
		cin>>a;
		somme[i] = somme[i - 1] + a;
	}
	cout<<2 * recursion(0 , N - 1) - somme[N]<<endl;
}