#include <iostream>
#include <algorithm>
#include <cstdio>
#define mod 1000000007
#define MN 110

int f[MN][MN], g[MN];
int h[MN], b[MN];
int c[MN];

int qpow(int x, int p)
{
	int ans = 1;
	while(p)
	{
		if(p & 1) ans = 1ll * ans * x % mod; 
		x = 1ll * x * x % mod; p >>= 1;
	}
	return ans;
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &h[i]), b[i] = h[i];
	std::sort(b + 1, b + n + 1); int N = std::unique(b + 1, b + n + 1) - b - 1;
	for(int i = 1; i <= n; i++) h[i] = std::lower_bound(b + 1, b + N + 1, h[i]) - b;
	b[0] = 1; for(int i = 1; i <= N; i++) c[i] = qpow(2, b[i] - b[i - 1]) - 1;
	g[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		if(h[i - 1] < h[i])
		{
			for(int j = 1; j <= h[i - 1]; j++) 
				f[i][j] = f[i - 1][j];
			for(int j = h[i - 1] + 1; j <= h[i]; j++)
				f[i][j] = 2 * g[i - 1] % mod;
			g[i] = 2 * g[i - 1] % mod;
		}
		else
		{
			for(int j = 1; j <= h[i]; j++)
				f[i][j] = 1ll * f[i - 1][j] * qpow(2, b[h[i - 1]] - b[h[i]]) % mod;
			g[i] = 2 * g[i - 1] % mod;
			for(int j = h[i] + 1; j <= h[i - 1]; j++)
				g[i] = (g[i] + 2ll * c[j] * f[i - 1][j] % mod * qpow(2, b[h[i - 1]] - b[j])) % mod;
		}
	}
	int ans = g[n]; 
	for(int i = 1; i <= h[n]; i++) ans = (ans + 1ll * c[i] * f[n][i] % mod * qpow(2, b[h[n]] - b[i])) % mod;
	printf("%d\n", ans);
}