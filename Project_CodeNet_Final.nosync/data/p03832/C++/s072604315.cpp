#include <bits/stdc++.h>
#define Pb push_back
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 7, Mod = 1e9 + 7;
inline int Mop ( int na ) { return na >= Mod ? na - Mod : na; }

inline int R()
{
    int rt = 0; char ch = getchar(); bool isn = false;
    for ( ; ch < '0' || ch > '9'; ch = getchar() ) isn = ch == '-' ? true : isn;
    for ( ; ch >= '0' && ch <= '9'; ch = getchar() ) rt = rt * 10 + ch - '0';
    return isn ? -rt : rt;
}

inline ll Pow ( ll bs, int t )
{
	ll rt = 1;
	for ( ; t; t >>= 1, bs = bs * bs % Mod )
		if ( t & 1 )
			rt = rt * bs % Mod;
	return rt;
}

ll c[MAXN][MAXN], dp[MAXN][MAXN];
ll g[MAXN][MAXN];
ll Get ( int x, int y )
{
	if ( x == y )
		return 1;
	if ( g[x][y] != -1 )
		return g[x][y];
	return g[x][y] = Get ( x - y, y ) * c[x - 1][y - 1] % Mod;
}

int main()
{
	int n = R(), a = R(), b = R(), cl = R(), d = R();
	memset ( g, -1, sizeof g );
	for ( int i = 0; i <= n; ++i )
		c[i][0] = 1;
	for ( int i = 1; i <= n; ++i )
		for ( int j = 1; j <= i; ++j )
			c[i][j] = Mop ( c[i - 1][j - 1] + c[i - 1][j] );
	dp[a - 1][0] = 1;
	for ( int i = a; i <= b; ++i )
		for ( int j = 0; j <= n; ++j )
		{
			dp[i][j] = dp[i - 1][j];
			for ( int k = cl; k <= d; ++k )
			{
				if ( j - k * i < 0 )
					break;
				dp[i][j] = Mop ( dp[i][j] + dp[i - 1][j - k * i] * c[j][k * i] % Mod * Get ( i * k, i ) % Mod );
			}
		}
	printf ( "%lld\n", dp[b][n] );
	return 0;
}