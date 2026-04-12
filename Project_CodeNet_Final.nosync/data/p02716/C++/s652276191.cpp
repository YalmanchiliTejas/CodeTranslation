#pragma GCC optimize ("Ofast")
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i=(a); i<(int)(b); i++)
#define FORD(i, a, b) for (int i=a; i>(int)(b); i--)
#define PPC(x) __builtin_popcount(x)
#define SZ(x) ((int)(x).size())
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define ithBit(m, i) ((m) >> (i) & 1)
#define ft first
#define sd second
#define kw(a) ((a) * (a))
#ifdef DEBUG
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;
 
const int maxN = 1 << 21;
const long long INF = 1000000000000000ll;

int T[maxN];

long long pref[maxN][2], suf[maxN][2], dp[maxN][3];

void solve()
{
	int n;
	scanf ("%d", &n);
	FOR(i, 1, n+1)
		scanf ("%d", T+i);
		
	FOR(i, 1, n+1)
	{
		pref[i][0] = pref[i-1][0];
		pref[i][1] = pref[i-1][1];
		pref[i][i&1] += T[i];	
		
		dbg("\n------");
		dbg(i); dbg(T[i]);
		dbg(pref[i][0]);
		dbg(pref[i][1]);
	}
	
	FORD(i, n, 0)
	{
		suf[i][0] = suf[i+1][0];
		suf[i][1] = suf[i+1][1];
		suf[i][i&1] += T[i];
		
		
		dbg("\n------");
		dbg(i); dbg(T[i]);
		dbg(suf[i][0]);
		dbg(suf[i][1]);
	}
	
	
	FOR(i, 0, n+1) FOR(s, 0, 3)
		dp[i][s] = -INF;
	dp[0][0] = 0, dp[1][0] = T[1];
	FOR(i, 2, n+1)
	{
		dp[i][0] = dp[i-2][0] + T[i];
		if (i != 2)
			dp[i][1] = T[i] + max(dp[i-2][1], dp[i-3][0]);
		if (i != 2)
			dp[i][2] = T[i] + max(dp[i-2][2], dp[i-3][1]);
	}
		
	long long res = -INF;
	
	if (n % 2 == 0)
		res = max({pref[n][0], pref[n][1], dp[n][1]});
		
	else
	{
		res = pref[n-1][0];	
		dbg(res);
		FOR(i, 2, n+1)
		{
			long long prop = pref[i-2][i&1] + suf[i+1][(i&1)^1];
			dbg(prop);
			res = max(res, prop);
		}
		res = max(res, dp[n][2]);		
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

