#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <numeric>
#define FOR(i, a, n) for (int i = (a); i < (n); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	char field[100][100];
	int Hs[100], Ws[100];
	int H, W;
	int status = 0;

	cin >> H >> W;

	REP(k, H)
	{
		REP(l, W)
		{
			cin >> field[k][l];
		}
	}

	REP(i, H)
	{
		status = 0;
		REP(j, W)
		{
			if (field[i][j] == '#')
			{
				status = 1;
			}
		}
		if (status == 0)
		{
			H = H - 1;
			FOR(k, i, H)
			{
				REP(l, W)
				{
					field[k][l] = field[k + 1][l];
				}
			}
			i--;
		}
	}

	REP(i, W)
	{
		status = 0;
		REP(j, H)
		{
			if (field[j][i] == '#')
			{
				status = 1;
			}
		}
		if (status == 0)
		{
			W = W - 1;
			FOR(k, i, W)
			{
				REP(l, H)
				{
					field[l][k] = field[l][k + 1];
				}
			}
			i--;
		}
	}


	REP(i, H)
	{
		REP(j, W)
		{
			cout << field[i][j];
		}
		cout << endl;
	}
	return 0;
}