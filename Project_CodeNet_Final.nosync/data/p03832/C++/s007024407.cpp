#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	const ll MOD = 1e9 + 7;
	ll N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;

	vector<ll> v(N + 1);
	vector<ll> vi(N + 1);
	vector<ll> inv(N + 1);
	for (int i = 0; i <= N; ++i) {
		if (i < 2) {
			v[i] = 1;
			vi[i] = 1;
			inv[i] = 1;
		} else {
			inv[i] = (-MOD / i) * inv[MOD % i] % MOD;
			v[i] = v[i - 1] * i % MOD;
			vi[i] = vi[i - 1] * inv[i] % MOD;
		}
	}
	vector<vector<ll>> dp(B + 1, vector<ll>(N + 1, 0));
	dp[A - 1][0] = 1;
	for (int i = A; i <= B; ++i) {
		for (int j = 0; j <= N; ++j) {
			if (dp[i - 1][j] == 0) { continue; }
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;

			ll tmp = 1;
			for (int k = 1; (k <= D) && (j + i*k <= N); ++k) {
				int key = N - j - i*(k - 1);
				tmp = tmp * v[key] % MOD * vi[i] % MOD * vi[key - i] % MOD * inv[k] % MOD;
				if (k >= C) {
					dp[i][j + i*k] = (dp[i][j + i*k] + dp[i - 1][j]*tmp + MOD) % MOD;
				}
			}
		}
	}

	ll res = (dp[B][N] + MOD) % MOD;
	cout << res << endl;

	return 0;
}
