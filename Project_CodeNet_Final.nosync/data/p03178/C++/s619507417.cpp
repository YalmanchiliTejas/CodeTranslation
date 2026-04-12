#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 10010;
const int MAXD = 110;
const int MAXC = 11;
const int MOD = 1000 * 1000 * 1000 + 7;
int nbCombi[MAXN][MAXD][MAXC];
int32_t main()
{
	string K;
	cin >> K;
	int D;
	cin >> D;
	nbCombi[0][0][0] = 1;
	for (int iNombre = 1 ; iNombre <= (int)K.size() ; iNombre++)
	{
		for (int iMod = 0 ; iMod < D ; iMod++)
		{
			for (int iC = 0 ; iC < 10 ; iC++)
			{
				for (int iPrec = 0 ; iPrec < 10 ; iPrec++)
				{
					nbCombi[iNombre][iMod][iC] =(nbCombi[iNombre][iMod][iC] +  nbCombi[iNombre - 1][((iMod - iC) % D + D)  % D][iPrec]) % MOD;	
				}
			}
		}
	}
	int nbReponses = 0;
	int resteActuel = 0;
	for (int iPos = K.size()  ; iPos > 0 ; iPos--)
	{
		int stop = (K[K.size() - iPos] - '0');
		if (iPos == 1) stop++;
		for (int j = 0 ; j <stop ; j++)
		{
			nbReponses =(nbReponses +  nbCombi[iPos][(D - resteActuel) % D][j]) % MOD ;
		}

		resteActuel = (resteActuel + (K[K.size() - iPos] - '0')) % D;
	}
	cout<<(nbReponses - 1 + MOD) % MOD<<endl;
	return 0;
}