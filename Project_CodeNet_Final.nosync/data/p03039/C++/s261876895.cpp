#include <iostream>
#include <cstdio>
#define MN 200000
#define mod 1000000007

int fac[MN + 5], Inv[MN + 5], inv[MN + 5];
int n, m, k;

int C(int a, int b) {if(a < b) return 0; return 1ll * fac[a] * inv[b] % mod * inv[a - b] % mod;}

int solve(int n, int m)
{
	int ans = 0;
	int w = 0;
	for(int b = 1; b <= std::min(n, k); b++) w = (w + 1ll * b * (k - b) % mod * C(n * (m - 1), k - b) % mod * C(n, b)) % mod;
	for(int a = 1; a <= m; a++)
	{
		int P = 1ll * Inv[m - 1] * (a - 1 - (m - a) + mod) % mod;
		ans = (ans + 1ll * w * P % mod * a) % mod;
	}
	return ans;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	
	fac[0] = Inv[0] = Inv[1] = inv[0] = 1;
	for(int i = 1; i <= MN; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	for(int i = 2; i <= MN; i++) Inv[i] = 1ll * (mod - mod / i) * Inv[mod % i] % mod;
	for(int i = 1; i <= MN; i++) inv[i] = 1ll * Inv[i] * inv[i - 1] % mod;
	
	printf("%d\n", (solve(n, m) + solve(m, n)) % mod);
	
}