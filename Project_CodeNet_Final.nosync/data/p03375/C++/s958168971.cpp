#include <iostream>
#include <cstdio>
#define MN 3010

int n, mod;
int f[MN][MN], C[MN][MN], mi[MN * MN];

int qpow(int x, int p, int mod)
{
	int ans = 1;
	for(; p; p >>= 1, x = 1ll * x * x % mod) if(p & 1) ans = 1ll * ans * x % mod;
	return ans;
}

int main()
{
	scanf("%d%d", &n, &mod);
	for(int i = 0; i <= n; i++) C[i][0] = C[i][i] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= i; j++)
			f[i][j] = (1ll * f[i - 1][j] * (j + 1) + f[i - 1][j - 1]) % mod; 
	mi[0] = 1; for(int i = 1; i <= n * n; i++) mi[i] = 2 * mi[i - 1] % mod;
	int ans = 0;
	for(int i = 0; i <= n; i++)
	{
		int w = 1ll * (i & 1 ? mod - 1 : 1) * C[n][i] % mod * qpow(2, qpow(2, n - i, mod - 1), mod) % mod;
		for(int j = 0; j <= i; j++) ans = (ans + 1ll * w * f[i][j] % mod * mi[(n - i) * j]) % mod;
	}
	printf("%d\n", ans);
}