#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 10005, mod = 998244353;

char A[maxn], B[maxn];
int n, f[maxn][maxn], fac[maxn], ifac[maxn];

inline int fpow(int x, int k)
{
	int res = 1;
	while (k) {
		if (k & 1) res = (ll)res * x % mod;
		k >>= 1; x = (ll)x * x % mod;
	}
	return res;
}

inline int C(int m, int n) {return (ll)fac[m] * ifac[n] % mod * ifac[m - n] % mod;}

int main()
{
	scanf("%s\n%s", A + 1, B + 1);
	n = strlen(A + 1);
	
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = (ll)fac[i - 1] * i % mod;
	ifac[n] = fpow(fac[n], mod - 2);
	for (int i = n - 1; ~i; --i) ifac[i] = (ll)ifac[i + 1] * (i + 1) % mod;

	int s1 = 0, s2 = 0;
	for (int i = 1; i <= n; ++i)
		s1 += A[i] == '1' && B[i] == '1', s2 += A[i] == '1' && B[i] == '0';

	for (int i = 0; i <= s2; ++i) f[0][i] = (ll)fac[i] * fac[i] % mod;
	for (int i = 1; i <= s1; ++i)
		for (int j = 1; j <= s2; ++j)
			f[i][j] = ((ll)f[i - 1][j] * i % mod * j + (ll)f[i][j - 1] * j % mod * j) % mod;

	int ans = 0;
	for (int i = 0; i <= s1; ++i)
		ans = (ans + (ll)f[s1 - i][s2] * fac[i] % mod * fac[i] % mod * C(s1, i) % mod * C(s1 + s2, i)) % mod;
	printf("%d\n", ans);
	return 0;
}
