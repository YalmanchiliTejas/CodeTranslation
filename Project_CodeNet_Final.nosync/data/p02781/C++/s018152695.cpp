#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ll> point;
#define F first
#define S second

string s; int k, n;
ll dp[2][4][105];

ll f(int low, int g, int p)
{
	if (g > k) return 0;
	if (p == n)
		return g == k;
	ll &r = dp[low][g][p];
	if (r != -1) return r;
	r = 0;
	for (int j = 0, to = low ? 9 : (s[p]-'0'); j <= to; ++j)
		r += f(low || j < (s[p]-'0'), g + (j != 0), p + 1);
	return r;
}

int main()
{
	#ifdef DGC
		//freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> s >> k;
	memset(dp, -1, sizeof dp);
	n = s.length();
	cout << f(0, 0, 0) << "\n";

	return 0;
}
