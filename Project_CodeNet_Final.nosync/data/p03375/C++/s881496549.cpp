#include <bits/stdc++.h>
#define inv(x) Power(x, mod - 2)
#define N 3005

using namespace std;
typedef long long ll;

int n, mod;
inline int add(int x, int y) { return (x += y) - (x >= mod ? mod : 0); }
inline void inc(int &x, int y) { x += y; x -= (x >= mod ? mod : 0); }

inline int Power(int x, int y, int M = mod) {
	int res = 1;
	while (y) {
		if (y & 1) res = (ll) res * x % M;
		x = (ll) x * x % M, y >>= 1;
	} return res;
}

int fac[N], ifac[N];
void init(int n) {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = (ll) fac[i - 1] * i % mod;
	ifac[n] = inv(fac[n]);
	for (int i = n - 1; i; --i) ifac[i] = (ll) ifac[i + 1] * (i + 1) % mod;
}

int C(int x, int y) {
	if (x < y || y < 0) return 0;
	return (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

int g[N][N];
int f[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> mod, init(n);
	
	for (int i = 0; i <= n; ++i) {
		g[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			g[i][j] = add(g[i - 1][j - 1], (ll) g[i - 1][j] * (j + 1) % mod);
	}
	
	for (int i = 0; i <= n; ++i) {
		ll tmp = Power(2, Power(2, n - i, mod - 1)), tmpb = Power(2, n - i);
		for (int j = 0, Pow = 1; j <= i; ++j, Pow = tmpb * Pow % mod)
			inc(f[i], (ll) Pow * g[i][j] % mod);
		f[i] = (ll) f[i] * tmp % mod;
	}
		
	
	ll ans = 0;
	for (int i = 0, flag = 1; i <= n; ++i, flag ^= 1) {
		ll c = C(n, i);
		if (!flag) c = mod - c;
		ans += c * f[i] % mod;
	}
	
	printf("%lld\n", ans % mod);
	return 0;
}