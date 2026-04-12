#include <bits/stdc++.h>
using namespace std;
const int MAXn = 2e5 + 10, MOD = 1e9 + 7;
typedef long long ll;
#define int ll

int n, m, k, inv[MAXn], fact[MAXn], ans;

int comb(int kk, int nn) {
	return (fact[nn] * ((inv[nn-kk] * inv[kk]) % MOD)) % MOD;
}
int32_t main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	inv[0] = fact[0] = inv[1] = fact[1] = 1;
	for (int i = 2; i < MAXn; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
		inv[i] = ((MOD - MOD / i) * inv[MOD % i]) % MOD;
	}
	for (int i = 1; i < MAXn; i++)
		inv[i] = (inv[i] * inv[i-1]) % MOD;
//	cout << comb(2, 5) << endl;
	for (int i = 1; i <= n; i++) {
		ans += (i * ((((((i - 1) * m) % MOD) * m) * comb(k-2, n * m - 2)) % MOD)) % MOD;
		ans %= MOD;
		ans += ((MOD - i) * ((((((n - i) * m) % MOD) * m) * comb(k-2, n * m - 2)) % MOD)) % MOD;
		ans %= MOD;
	}
	for (int i = 1; i <= m; i++) {
		ans += (i * ((((((i - 1) * n) % MOD) * n) * comb(k-2, n * m - 2)) % MOD)) % MOD;
		ans %= MOD;
		ans += ((MOD - i) * ((((((m - i) * n) % MOD) * n) * comb(k-2, n * m - 2)) % MOD)) % MOD;
		ans %= MOD;
	}
	cout << ans;
}
