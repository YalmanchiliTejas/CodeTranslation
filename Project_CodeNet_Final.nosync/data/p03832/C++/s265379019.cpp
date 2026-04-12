#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll fi[1010], dp[1010];

ll modpow(ll x, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	dp[n] = 1;
	for (int i = 1; i <= n; i++) dp[n] = dp[n] * i % MOD;
	fi[n] = modpow(dp[n], MOD - 2);
	for (int i = n; i > 0; i--) fi[i - 1] = fi[i] * i % MOD;
	for (int i = a; i <= b; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = c; k <= d; k++) {
				if (j + i * k > n) break;
				(dp[j] += dp[j + i * k] * modpow(fi[i], k) % MOD * fi[k] % MOD) %= MOD;
			}
		}
	}
	cout << dp[0] << endl;
	return 0;
}