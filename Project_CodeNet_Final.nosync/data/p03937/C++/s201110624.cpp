#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#ifdef WIN32
	#define LL "%I64d"
#else
	#define LL "%lld"
#endif

#ifdef CT
	#define debug(...) printf(__VA_ARGS__)
	#define setfile() 
#else
	#define debug(...)
	#define filename ""
	#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout)
#endif

#define R register
#define getc() (S == T && (T = (S = B) + fread(B, 1, 1 << 15, stdin), S == T) ? EOF : *S++)
#define dmax(_a, _b) ((_a) > (_b) ? (_a) : (_b))
#define dmin(_a, _b) ((_a) < (_b) ? (_a) : (_b))
#define cmax(_a, _b) (_a < (_b) ? _a = (_b) : 0)
#define cmin(_a, _b) (_a > (_b) ? _a = (_b) : 0)
#define cabs(_x) ((_x) < 0 ? (- (_x)) : (_x))
char B[1 << 15], *S = B, *T = B;
inline int F()
{
	R char ch; R int cnt = 0; R bool minus = 0;
	while (ch = getc(), (ch < '0' || ch > '9') && ch != '-') ;
	ch == '-' ? minus = 1 : cnt = ch - '0';
	while (ch = getc(), ch >= '0' && ch <= '9') cnt = cnt * 10 + ch - '0';
	return minus ? -cnt : cnt;
}
#define maxn 10
char mp[maxn][maxn];
int n, m;
void dfs(int x, int y)
{
	if (x == n && y == m)
	{
		puts("Possible");
		exit(0);
		return ;
	}
	if (x < n && mp[x + 1][y] == '#') dfs(x + 1, y);
	if (y < m && mp[x][y + 1] == '#') dfs(x, y + 1);
}
int main()
{
//	setfile();
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (mp[i][j] == '#')
				++cnt;
	if (cnt != n + m - 1) {puts("Impossible"); return 0;}
	dfs(1, 1);
	puts("Impossible");
	return 0;
}
