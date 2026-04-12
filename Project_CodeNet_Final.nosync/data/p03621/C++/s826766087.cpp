#include <bits/stdc++.h>
typedef long long ll;
constexpr int MAXN = 1e4 + 10, mo = 998244353;
inline ll fpm(ll a, ll b = mo - 2)
{
	ll res = 1;
	while (b)
	{
		if (b & 1) res = res * a % mo;
		a = a * a % mo;
		b >>= 1;
	}
	return res;
}
char a[MAXN], b[MAXN];
int fact[MAXN], invfac[MAXN], f[MAXN][MAXN];
inline int C(int n, int m)
{
	if(n < m || n < 0 || m < 0) return 0;
	return 1ll * fact[n] * invfac[m] % mo * invfac[n - m] % mo;
}
int main()
{
	scanf("%s%s", a, b);
	const int n = strlen(a);
	for(int i = fact[0] = 1; i <= n; ++i)
		fact[i] = 1ll * fact[i - 1] * i % mo;
	invfac[n] = fpm(fact[n]);
	for(int i = n; i; --i)
		invfac[i - 1] = 1ll * invfac[i] * i % mo;
	int s1 = 0, s2 = 0;
	for(int i = 0; i < n; s1 += (a[i] == '1' && b[i] == '1'), s2 += (a[i] == '1' && b[i] == '0'), ++i);
	for(int i = 0; i <= s2; ++i)
		f[0][i] = 1ll * fact[i] * fact[i] % mo;
	for(int i = 1; i <= s1; ++i)
		for(int j = 1; j <= s2; ++j)
			f[i][j] = (1ll * f[i - 1][j] * i % mo * j % mo + 1ll * f[i][j - 1] * j % mo * j % mo) % mo;
	int ans = 0;
	for(int i = 0; i <= s1; ++i)
		ans = (ll)(ans + 1ll * f[s1 - i][s2] * fact[i] % mo * fact[i] % mo * C(s1, i) % mo * C(s1 + s2, i) % mo) % mo;
	printf("%d\n", ans);
	return 0;
}