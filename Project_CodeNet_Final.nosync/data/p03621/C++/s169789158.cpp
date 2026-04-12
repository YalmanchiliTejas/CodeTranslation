#include <algorithm>
#include <cstring>
#include <cstdio>
#define MOD 998244353
#define GEN 3
typedef long long ll; 
inline int sum(int x, int y)
{
	x += y; 
	if (x >= MOD)
		x -= MOD; 
	return x; 
}
inline int sub(int x, int y)
{
	x -= y; 
	if (x < 0)
		x += MOD; 
	return x; 
}
inline int quick_pow(int a, int n)
{
	int res = 1; 
	while (n)
	{
		if (n & 1)
			res = (ll)res * a % MOD; 
		a = (ll)a * a % MOD; 
		n >>= 1; 
	}
	return res; 
}
int alpha[2][40005], poly_rev[40005], poly_ntt_lst = -1; 
inline void poly_ntt_init(int n)
{
	if (poly_ntt_lst == n)
		return;
	poly_ntt_lst = n;
	alpha[0][0] = alpha[1][0] = 1; 
	alpha[0][1] = quick_pow(GEN, (MOD - 1) / n); 
	alpha[1][1] = quick_pow(alpha[0][1], MOD - 2); 
	for (int i = 2; i <= n; i++)
	{
		for (int x = 0; x < 2; x++)
			alpha[x][i] = (ll)alpha[x][1] * alpha[x][i - 1] % MOD; 
	}
	for (int i = 1, j = n >> 1; i + 1 < n; i++)
	{
		poly_rev[i] = j; 
		int k = n >> 1; 
		while (j >= k)
		{
			j -= k; 
			k >>= 1; 
		}
		j += k;
	}
}
inline void poly_ntt(int *arr, int n, bool f)
{
	poly_ntt_init(n); 
	for (int i = 1; i + 1 < n; i++)
	{
		if (i < poly_rev[i])
			std::swap(arr[i], arr[poly_rev[i]]); 
	}
	for (int i = 1; i < n; i <<= 1)
	{
		for (int j = 0, off = n / (i << 1); j + i < n; j += i << 1)
		{
			for (int k = j, cur = 0; k < j + i; k++, cur += off)
			{
				int x = (ll)arr[k + i] * alpha[f][cur] % MOD; 
				arr[k + i] = sub(arr[k], x); 
				arr[k] = sum(arr[k], x); 
			}
		}
	}
	if (f)
	{
		int x = quick_pow(n, MOD - 2); 
		for (int i = 0; i < n; i++)
			arr[i] = (ll)arr[i] * x % MOD; 
	}
}
inline void poly_mul(int *a, int *B, int n, int m)
{
	static int b[40005];
	int len = 1; 
	while (len < n + m - 1)
		len <<= 1; 
	memcpy(b, B, m << 2);
	memset(b + m, 0, len - m << 2);
	memset(a + n, 0, len - n << 2);
	poly_ntt(a, len, false); 
	poly_ntt(b, len, false); 
	for (int i = 0; i < len; i++)
		a[i] = (ll)a[i] * b[i] % MOD; 
	poly_ntt(a, len, true); 
}
ll fact[10005], inv[10005];
int dp[40005], f[40005];
char s[10005], t[10005];
int main()
{
	// freopen("AGC019-E.in", "r", stdin);
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= 10000; i++)
	{
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = quick_pow(fact[i], MOD - 2);
	}
	scanf("%s%s", s, t);
	int n = 0, m = 0;
	for (int i = 0; s[i]; i++)
	{
		n += s[i] == '1' && t[i] == '0';
		m += s[i] == '1' && t[i] == '1';
	}
	for (int i = 0; i <= m; i++)
		f[i] = inv[i + 1];
	dp[0] = 1;
	for (int i = 0; i < 20; i++)
	{
		if (n & (1 << i))
			poly_mul(dp, f, m + 1, m + 1);
		poly_mul(f, f, m + 1, m + 1);
	}
	ll ans = 0;
	for (int i = 0; i <= m; i++)
		(ans += dp[i]) %= MOD;
	printf("%lld\n", ans * fact[n] % MOD * fact[m] % MOD * fact[n + m] % MOD);
	return 0;
}
