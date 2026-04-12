#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>
#include <deque>
#include <bitset>

#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) v.erase(remove(v.begin(), v.end(), a), v.end())
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define REPE(i, n) for (int (i) = 0; (i) <= (n); (i)++)
using namespace std;

int A, B;
int D[100][100];

int F[101][101];
int G[101][101];

void Set(int p, int q)
{
	int min_f = INT_MAX;

	for (int f = 0; f <= 100; f++)
	{
		bool is_update = false;

		REP(x, A) REP(y, B)
		{
			int d = p * (x + 1) + q * (y + 1) + f;
			if (D[x][y] > d)
			{
				is_update = false;
				goto BREAK;
			}
			if (G[x][y] > d && D[x][y] == d)
			{
				is_update = true;
			}
		}
	BREAK:
		if (is_update)
		{
			min_f = MIN(f, min_f);
		}
	}

	if (min_f <= 100)
	{
		F[p][q] = min_f;

		REP(x, 101) REP(y, 101)
		{
			int d = p * (x + 1) + q * (y + 1) + min_f;
			G[x][y] = MIN(G[x][y], d);
		}
	}
}

signed main()
{
	cin >> A >> B;
	REP(a, A)
	{
		REP(b, B)
		{
			cin >> D[a][b];
		}
	}
	REP(i, 101) REP(j, 101)
	{
		F[i][j] = 100;
		G[i][j] = 100;
	}

	REP(p, 101) REP(q, 101)
	{
		Set(p, q);
	}

	REP(x, A) REP(y, B)
	{
		int min = INT_MAX;
		REP(p, 101) REP(q, 101)
		{
			int d = p * (x + 1) + q * (y + 1) + F[p][q];
			min = MIN(min, d);
		}
		if (D[x][y] != min)
		{
			cout << "Impossible" << endl;
			exit(0);
		}
	}

	cout << "Possible" << endl;
	cout << "202 10401" << endl;
	REP(i, 100) cout << (i + 1) << " " << (i + 2) << " X" << endl;
	REP(i, 100) cout << (i + 102) << " " << (i + 103) << " Y" <<  endl;

	REP(p, 101) REP(q, 101)
	{
		cout << (p + 1) << " " << (202 - q) << " " << F[p][q] << endl;
	}

	cout << "1 202" << endl;
}