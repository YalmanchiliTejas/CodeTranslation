#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define mod 998244353
#define N 10000005
int n;
int fac[N], inv[N], mul[N];
int Pow(int a, int k)
{
	int ret = 1;
	while (k)
	{
		if (k & 1)
			ret = (ll)ret * a % mod;
		a = (ll)a * a % mod;
		k >>= 1;
	}
	return ret;
}
int C(int n, int m){return (ll)fac[n] * inv[m] % mod * inv[n - m] % mod;}
int main()
{
	scanf("%d", &n);
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (ll)fac[i - 1] * i % mod;
	inv[n] = Pow(fac[n], mod - 2);
	for (int i = n; i >= 1; i--)
		inv[i - 1] = (ll)inv[i] * i % mod;
	mul[0] = 1;
	for (int i = 1; i <= n; i++)
		mul[i] = (ll)mul[i - 1] * 2 % mod;
	int ans = Pow(3, n);
	for (int i = n / 2 + 1; i <= n; i++)
		ans = (ans - 2ll * mul[n - i] * C(n, i)) % mod;
	if (ans < 0)ans += mod;
	printf("%d\n", ans);
}
