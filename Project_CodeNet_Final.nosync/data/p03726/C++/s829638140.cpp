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
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
 
int f[100010], g[100010], n;
vector < int > G[100010];
 
inline void dfs(int x, int fa = 0)
{
	f[x] = 1;
	g[x] = 0;
	for(auto y : G[x]) 
		if(y ^ fa) dfs(y, x), f[x] += g[y], g[x] += max(f[y], g[y]);
}
 
int main()
{
	n = read();
	for(int i = 1, x, y; i < n; i ++) 
		x = read(), y = read(), G[x].pb(y), G[y].pb(x);
	dfs(1);
	return 
	puts( max( f[1], g[1] ) <= n / 2 ? "Second" : "First" ), 0;
}