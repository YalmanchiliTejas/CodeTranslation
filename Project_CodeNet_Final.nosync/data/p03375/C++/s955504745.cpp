#include<bits/stdc++.h>
using namespace std;
int n, s[3007][3007], fac[3007], inv[3007], res, mod;
int fpow(int a, int x, int mod)
{
	int res = 1;
	while (x)
	{
		if (x & 1)res = 1LL * res * a % mod;
		a = 1LL * a * a % mod;
		x >>= 1;
	}
	return res;
}
int main()
{
	cin >> n >> mod;
	s[0][0] = 1;
	for (int i = 1; i <= n + 1; i++)
		for (int j = 1; j <= n + 1; j++)
			s[i][j] = (1LL * s[i - 1][j] * j % mod + s[i - 1][j - 1]) % mod;
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i <= n; i++)
		fac[i] = 1LL * fac[i - 1] * i % mod;
	for (int i = 2; i <= n; i++)
		inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 2; i <= n; i++)
		inv[i] = 1LL * inv[i - 1] * inv[i] % mod;
	for (int i = 0; i <= n; i++)
	{
		int tot = 0;
		int a = fpow(2, fpow(2, n - i, mod - 1), mod);
		int b = fpow(2, n - i, mod);
		for (int j = 0, k = 1; j <= i; j++, k = 1LL * k * b % mod)
			tot = (tot + 1LL * s[i + 1][j + 1] * a % mod * k % mod) % mod;
		res = (res + 1LL * (i & 1 ? mod - 1 : 1) * fac[n] % mod * inv[i] % mod * inv[n - i] % mod * tot % mod) % mod;
	}
	cout << res << endl;
	return 0;
}