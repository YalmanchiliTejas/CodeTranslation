#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 10000005, mod = 998244353;

inline int gi()
{
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	int sum = 0;
	while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
	return sum;
}

inline int fpow(int x, int k)
{
	int res = 1;
	while (k) {
		if (k & 1) res = (ll)res * x % mod;
		k >>= 1; x = (ll)x * x % mod;
	}
	return res;
}

int n, fac[maxn], ifac[maxn], Pow[maxn];

inline int C(int m, int n)
{
	return (ll)fac[m] * ifac[n] % mod * ifac[m - n] % mod;
}

int main()
{
	n = gi();
	fac[0] = 1; Pow[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = (ll)fac[i - 1] * i % mod;
	ifac[n] = fpow(fac[n], mod - 2);
	for (int i = n - 1; ~i; --i) ifac[i] = (ll)ifac[i + 1] * (i + 1) % mod;
	for (int i = 1; i <= n / 2 + 1; ++i) Pow[i] = Pow[i - 1] + Pow[i - 1], Pow[i] = Pow[i] >= mod ? Pow[i] - mod : Pow[i];
	
	int ans = fpow(3, n);
	for (int i = n / 2 + 1; i <= n; ++i)
		ans = (ans + (ll)(mod - C(n, i)) * Pow[n - i + 1]) % mod;
	printf("%d\n", ans);
	
	return 0;
}
