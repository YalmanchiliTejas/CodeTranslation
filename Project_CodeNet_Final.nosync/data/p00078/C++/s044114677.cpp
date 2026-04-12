#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <map>
#include <functional>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <typeinfo>
#define PI 3.14159265359
#define INF 99999999
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(n) rep(i, n)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int n;
int masu[15][15];
int nowx, nowy;

int main()
{
	while (cin >> n, n)
	{
		rep(i, n) rep(j, n) masu[i][j] = 0;
		masu[n/2+1][n/2] = 1;
		nowx = n / 2;
		nowy = n / 2 + 1;

		for (int i=2; i<=n*n; i++)
		{
			nowx = (nowx + 1) % n;
			nowy = (nowy + 1) % n;
			if (masu[nowy][nowx] == 0)
			{
				masu[nowy][nowx] = i;
			} else {
				while (masu[nowy][nowx] != 0)
				{
					nowy = (nowy + 1) % n;
					nowx = nowx - 1;
					if (nowx < 0) nowx = n + nowx;
				}
				masu[nowy][nowx] = i;
			}
		}

		rep(i, n)
		{
			rep(j, n)
			{
				printf("%4d", masu[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}