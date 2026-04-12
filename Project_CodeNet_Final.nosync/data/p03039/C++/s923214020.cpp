#include <bits/stdc++.h>
#include <bits/basic_ios.h>

using namespace std;

#define int long long

typedef long long li;
typedef long double ld;

void solve();

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(20);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

int modexp (int a, int b, int m) {
	if (b == 0) return 1;
	int ans = modexp(a, b/2, m);
	ans = (ans * ans) % m;
	if (b & 1) ans = (ans * a) % m;
	return ans;
}
int mod = 1e9 + 7;
int n, m, k;
int inverse[(int) 2e5];
void solve() {
	inverse[(int) 2e5 - 1] = modexp((int) 2e5 - 1, mod - 2, mod);
	for (int i = 2e5 - 2; i >= 1; i--) {
		inverse[i] = modexp(i, mod - 2, mod);
	}
	cin >> n >> m >> k;
	int contri = 1;
	// contri = C(n * m - 2, k - 2)
	// a * (a - 1) * ... * (a - b + 1) / (1 * 2 * ... * b)
	for (int i = n * m - 2; i >= n * m - 2 - (k - 2) + 1; i--) {
		int j = i % mod;
		contri *= j, contri %= mod;
	}
	for (int i = 1; i <= k - 2; i += 1) {
		contri *= inverse[i], contri %= mod;
	}
	int ans = 0;
	for (int i = 1; i <= n; i += 1) {
		int s = (i * (i - 1)) / 2;
		s %= mod;
		s *= m, s %= mod;
		s *= m, s %= mod;
		s *= contri, s %= mod;
		ans += s, ans %= mod;
	}
	for (int i = 1; i <= m; i += 1) {
		int s = (i * (i - 1)) / 2;
		s %= mod;
		s *= n, s %= mod;
		s *= n, s %= mod;
		s *= contri, s %= mod;
		ans += s, ans %= mod;
	}
	cout << ans;
}