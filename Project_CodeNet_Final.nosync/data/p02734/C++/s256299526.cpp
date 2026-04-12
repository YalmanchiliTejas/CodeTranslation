#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i=(a); i<(int)(b); i++)
#define FORD(i, a, b) for (int i=a; i>(int)(b); i--)
#define PPC(x) __builtin_popcount(x)
#define SZ(x) ((int)(x).size())
#define MSB(x) (31 - __builtin_clz(x))
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define ithBit(m, i) ((m) >> (i) & 1)
#define ft first
#define sd second
#ifdef DEBUG
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;
 
const int maxN = 3006, mod = 998244353;

int T[maxN];
long long dp[maxN][maxN], dp2[maxN][maxN];

void solve()
{
	int n, s;
	scanf ("%d%d", &n, &s);
	FOR(i, 1, n+1)
		scanf ("%d", T+i);
	dp[0][0] = 1ll;
	FOR(i, 1, n+1)
	{
		dp[i][0] = i+1;
		FOR(j, 1, s+1)
		{
			if (T[i] <= j)	
				dp2[i][j] = dp[i-1][j-T[i]];
			dp[i][j] = (dp[i-1][j] + dp2[i][j]) % mod;
		}
	}	
	long long res = 0;
	FOR(i, 1, n+1)
	{
		dp2[i][s] *= (n+1-i);
		res = (res + dp2[i][s]) % mod;
	}
	printf("%lld\n", res);
}
 
int main()
{
	int t;
	t=1;//scanf ("%d", &t);
	while (t--)
		solve();
	return 0;
}
