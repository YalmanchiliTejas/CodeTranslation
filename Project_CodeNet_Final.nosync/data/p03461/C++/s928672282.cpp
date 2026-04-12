#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <string.h>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

const LL MOD = 1000000007;
const int INF = 1000000007;
const LL LINF = 1LL * INF * INF;
const int MAXN = 100007;
const LD EPS = 1e-7;

const int MAXA = 17;

int D[MAXA][MAXA], C[MAXA][MAXA];
vector <pair <PII, int> > E;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	int a, b, n = 202;
	cin >> a >> b;
	FOR(i, 1, a + 1)
		FOR(j, 1, b + 1)
	{
		cin >> D[i][j];
		C[i][j] = INF;
	}
	REP(c1, 101)
		REP(c2, 101)
		REP(c3, 101)
	{
		bool ok = true, s = false;
		FOR(i, 1, a + 1)
			FOR(j, 1, b + 1)
		{
			int d = c1 * i + c2 * j + c3;
			if (d < D[i][j])
				ok = false;
			if (d == D[i][j] && C[i][j] > D[i][j])
				s = true;
		}
		if (ok && s)
		{
			FOR(i, 1, a + 1)
				FOR(j, 1, b + 1)
				C[i][j] = min(C[i][j], c1 * i + c2 * j + c3);
			E.push_back(MP(MP(c1 + 1, n - c2), c3));
		}
	}
	FOR(i, 1, a + 1)
		FOR(j, 1, b + 1)
	{
		if (C[i][j] > D[i][j])
		{
			cout << "Impossible\n";
			return 0;
		}
	}
	cout << "Possible\n";
	cout << n << ' ' << SZ(E) + n - 2 << '\n';
	REP(i, (n - 2) / 2)
		cout << i + 1 << ' ' << i + 2 << " X\n";
	REP(i, (n - 2) / 2)
		cout << n - i - 1 << ' ' << n - i << " Y\n";
	REP(i, SZ(E))
		cout << E[i].first.first << ' ' << E[i].first.second << ' ' << E[i].second << '\n';
	cout << "1 " << n << endl;
	//cout << endl; system("pause");
	return 0;
}