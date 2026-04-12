#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define fill( x, y ) memset( x, y, sizeof x )
#define copy( x, y ) memcpy( x, y, sizeof x )
using namespace std;

typedef long long LL;
typedef pair < int, int > pa;

inline int read()
{
	int sc = 0, f = 1; char ch = getchar();
	while( ch < '0' || ch > '9' ) { if( ch == '-' ) f = -1; ch = getchar(); }
	while( ch >= '0' && ch <= '9' ) sc = sc * 10 + ch - '0', ch = getchar();
	return sc * f;
}

const int MAXN = 100010;

int f[MAXN], g[MAXN], n;
vector < int > G[MAXN];

inline void dfs(int x, int fa = 0)
{
	f[ x ] = 1, g[ x ] = 0;
	for( auto y : G[ x ] ) if( y ^ fa ) dfs( y, x ), f[ x ] += g[ y ], g[ x ] += max( f[ y ], g[ y ] );
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read();
	for( int i = 1, x, y ; i < n ; i++ ) x = read(), y = read(), G[ x ].pb( y ), G[ y ].pb( x );
	dfs( 1 );
	return puts( max( f[ 1 ], g[ 1 ] ) <= n / 2 ? "Second" : "First" ), 0;
}
