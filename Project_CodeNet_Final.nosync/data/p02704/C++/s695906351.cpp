#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int MAXN = 500;
unsigned long long sol[MAXN][MAXN];
int32_t main()
{
	int N;
	cin >> N;
	int lignes[N];
	int colonnes[N];
	int nbLignes = N;
	int nbColonnes = N;
	for (int i = 0 ; i < N ; i++)
	{
		cin >> lignes[i];
	}
	for (int i = 0 ; i < N ; i++)
	{
		cin >> colonnes[i];
	}

	int valLignes[N];
	int valColonnes[N];
	for (int i = 0 ; i < N ; i++)
	{
		cin >> valLignes[i];
	}
	for (int i = 0 ; i < N ; i++)
	{
		cin >> valColonnes[i];
	}

	for (int iBit = 0 ; iBit < 64 ; iBit++)
	{
		int actu[N][N];
		for (int i = 0 ; i < N ; i++)
		{
			for (int j = 0 ; j < N ; j++) actu[i][j] = 2;
		}
		vector <int> libreL;
		vector <int> libreC;
		for (int i = 0 ; i < nbLignes ; i++)
		{
			if (lignes[i] == 0) //and
			{
				if (valLignes[i] & (1ll<<iBit))
				{
					for (int j = 0 ; j < nbColonnes ; j++)
					{
						if (actu[i][j] == 0)
						{
							cout<<-1<<endl;
							exit(0);
						}
						actu[i][j] = 1;
					}
				}
				else
				{
					libreL.push_back(i);
				}
			}
			else
			{
				if ((valLignes[i] & (1ll<<iBit))==0)
				{
					for (int j = 0 ; j < nbColonnes  ; j++)
					{
						if (actu[i][j] == 1)
						{
							cout<<-1<<endl;
							exit(0);
						}
						actu[i][j] = 0;
					}
				}
				else
				{
					libreL.push_back(i);
				}
			}
		}

		for (int i = 0 ; i < nbColonnes ; i++)
		{
			if (colonnes[i] == 0) //and
			{
				if (valColonnes[i] & (1ll<<iBit))
				{
					for (int j = 0 ; j < nbLignes ; j++)
					{
						if (actu[j][i] == 0)
						{
							cout<<-1<<endl;
							exit(0);
						}
						actu[j][i] = 1;
					}
				}
				else
				{
					libreC.push_back(i);
				}
			}
			else
			{
				if ((valColonnes[i] & (1ll<<iBit))==0)
				{
					for (int j = 0 ; j < nbLignes  ; j++)
					{
						if (actu[j][i] == 1)
						{
							cout<<-1<<endl;
							exit(0);
						}
						actu[j][i] = 0;
					}
				}
				else
				{
					libreC.push_back(i);
				}
			}
		}
		if (libreC.size() > 1 && libreL.size() > 1)
		{
			int in = 0;
			for (auto lig : libreL)
			{
				int ij = 0;
				for (auto col : libreC)
				{
					if (in % 2 == ij % 2) actu[lig][col] = 0;
					else actu[lig][col] = 1;
					ij++;
				}
				in++;
			}
		}
		else
		{
			if (libreC.size() <= 1 && libreL.size() > 0)
			{
				for (auto lig : libreL)
				{
					bool estBon = false;
					for (int j = 0 ; j < nbColonnes ; j++)
					{
						if (lignes[lig] == 0 && actu[lig][j] == 0)
						{
							estBon = true;
						}
						else if (lignes[lig] == 1  && actu[lig][j] == 1)
						{
							estBon = true;
						}
					}
					if (estBon) continue;
					for (int j = 0 ; j < nbColonnes ; j++)
					{
						if (actu[lig][j] == 2)
						{
							if (lignes[lig] == 0)
							{
								actu[lig][j] = 0;
							}
							else actu[lig][j] = 1;
							estBon = true;
							break;
						}
					}
					if (!estBon) 
					{
						cout<<-1<<endl;
						exit(0);
					}
				}
				for (auto col : libreC)
				{
					bool estBon = false;
					for (int j = 0 ; j < nbLignes ; j++)
					{
						if (colonnes[col] == 0 && actu[j][col] == 0) estBon = true;
						else if (colonnes[col] == 1 && actu[j][col] == 1) estBon = true;
					}
					if (estBon) continue;
					for (int j = 0 ; j < nbColonnes ; j++)
					{
						if (actu[j][col] == 2)
						{
							if (colonnes[col] == 0)
							{
								actu[j][col] = 0;
							}
							else actu[j][col] = 1;
							estBon = true;
							break;
						}
					}
					if (!estBon)
					{ 
					cout<<-1<<endl;
					exit(0);
				}
				}
			}
			else if (libreL.size() <= 1 && libreC.size() > 0)
			{
				for (auto col : libreC)
				{
					bool estBon = false;
					for (int j = 0 ; j < nbLignes ; j++)
					{
						if (colonnes[col] == 0 && actu[j][col] == 0) estBon = true;
						else if (colonnes[col] == 1 && actu[j][col] == 1) estBon = true;
					}
					if (estBon) continue;
					for (int j = 0 ; j < nbLignes ; j++)
					{
						if (actu[j][col] == 2)
						{
							if (colonnes[col] == 0)
							{
								actu[j][col] = 0;
							}
							else actu[j][col] = 1;
							estBon = true;
							break;
						}
					}
					if (!estBon) 
					{
						cout<<-1<<endl;
						exit(0);
					}
				}

				for (auto lig : libreL)
				{
					bool estBon = false;
					for (int j = 0 ; j < nbColonnes ; j++)
					{
						if (lignes[lig] == 0 && actu[lig][j] == 0)
						{
							estBon = true;
						}
						else if (lignes[lig] == 1  && actu[lig][j] == 1)
						{
							estBon = true;
						}
					}
					if (estBon) continue;
					for (int j = 0 ; j < nbColonnes ; j++)
					{
						if (actu[lig][j] == 2)
						{
							if (lignes[lig] == 0)
							{
								actu[lig][j] = 0;
							}
							else actu[lig][j] = 1;
							estBon = true;
							break;
						}
					}
					if (!estBon) 
					{
						cout<<-1<<endl;
						exit(0);
					}
					
				}

				
			}
		}
		for (int i = 0 ; i < nbLignes ; i++)
		{
			for (int j = 0 ; j < nbColonnes ; j++)
			{
				if (actu[i][j] == 2) actu[i][j] = 0;
				sol[i][j] |= (actu[i][j] * (1ll<<iBit));
			}
		}
	}
	for (int i = 0 ; i < nbLignes ; i++)
	{
		for (int j = 0 ; j < nbColonnes ; j++)
		{
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
}