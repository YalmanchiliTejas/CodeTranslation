#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 1 << 15;
 
namespace math {
	const int mod = 998244353;
 
	int sum(int x, int y) {
		return x + y <= mod ? x + y : x + y - mod;
	}
 
	int product(int x, int y) {
		return 1ll * x * y % mod;
	}
 
	int pow_mod(int x, int n) {
		int y = 1;
		while (n) {
			if (n & 1) y = 1ll * y * x % mod;
			x = 1ll * x * x % mod;
			n >>= 1;
		}
		return y;
	}
 
	int fac[maxn], ifac[maxn], r[maxn];
 
	int C(int n, int m) {
		return m >= 0 && n >= m ? 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod : 0;
	}
 
	void pre() {
		int n = maxn - 1;
		fac[0] = 1;
		for (int i = 1; i <= n; ++i) {
			fac[i] = 1ll * fac[i - 1] * i % mod;
		}
		ifac[n] = pow_mod(fac[n], mod - 2);
		for (int i = n; i >= 1; --i) {
			ifac[i - 1] = 1ll * ifac[i] * i % mod;
		}
		for (int i = 0; i < maxn; ++i) {
			for (int j = 1; j < maxn; j <<= 1) {
				(r[i] <<= 1) |= ((i & j) ? 1 : 0);
			}
		}
		return;
	}
 
	const int proot = 3;
 
	void dft(int *a, bool rev = 0) {
		for (int i = 0; i < maxn; ++i) {
			if (r[i] < i) {
				swap(a[i], a[r[i]]);
			}
		}
		for (int l = 2; l <= maxn; l <<= 1) {
			int hl = l >> 1, wn = pow_mod(proot, (mod - 1) / l);
			if (rev) {
				wn = pow_mod(wn, mod - 2);
			}
			for (int i = 0; i < maxn; i += l) {
				int w = 1;
				for (int j = i, k = i | hl; j < (i | hl); ++j, ++k) {
					int x = a[j], y = 1ll * a[k] * w % mod;
					a[j] = (x + y) % mod;
					a[k] = (x + mod - y) % mod;
					w = 1ll * w * wn % mod;
				}
			}
		}
		if (rev) {
			int inv = pow_mod(maxn, mod - 2);
			for (int i = 0; i < maxn; ++i) {
				a[i] = 1ll * a[i] * inv % mod;
			}
		}
		return;
	}
}
 
char a[maxn], b[maxn];
int L, n, m;
int dp[maxn], c[maxn];
 
using namespace math;
 
int main() {
	math::pre();
	scanf("%s", a);
	scanf("%s", b);
	L = strlen(a);
	for (int i = 0; i < L; ++i) {
		if (a[i] == '1') {
			if (b[i] == '1') {
				++m;
			}
			else {
				++n;
			}
		}
	}
	dp[0] = 1;
	for (int j = 0; j <= m; ++j) {
		c[j] = ifac[j + 1];
	}
	for (int i = 1; i <= n; i <<= 1) {
		dft(c);
		if (n & i) {
			dft(dp);
			for (int j = 0; j < maxn; ++j) {
				dp[j] = 1ll * dp[j] * c[j] % mod;
			}
			dft(dp, 1);
			for (int j = (maxn >> 1) - 10; j < maxn; ++j) {
				dp[j] = 0;
			}
		}
		for (int j = 0; j < maxn; ++j) {
			c[j] = 1ll * c[j] * c[j] % mod;
		}
		dft(c, 1);
		for (int j = (maxn >> 1) - 10; j < maxn; ++j) {
			c[j] = 0;
		}
	}
	int ans = 0;
	for (int j = 0; j <= m; ++j) {
		ans = sum(ans, product(dp[j], fac[n + m]));
	}
	ans = product(ans, product(fac[n], fac[m]));
	printf("%d\n", ans);
	return 0;
}