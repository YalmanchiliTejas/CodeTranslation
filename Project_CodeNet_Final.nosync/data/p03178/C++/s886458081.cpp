#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

ll modpow(ll x, ll n, ll mod = MOD) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

ll dp[10005][100][2];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string K;
	int D;
	cin >> K >> D;
	dp[0][0][1] = 1;
	int n = K.size();
	for (int i = 0; i < n; i++) {
		int digit = K[i] - '0';
		for (int j = 0; j < D; j++) {
			for (int k = 0; k <= 9; k++) {
				(dp[i + 1][(j + k) % D][0] += dp[i][j][0]) %= MOD;
			}

			for (int k = 0; k < digit; k++) {
				(dp[i + 1][(j + k) % D][0] += dp[i][j][1]) %= MOD;
			}
			dp[i + 1][(j + digit) % D][1] += dp[i][j][1];
		}
	}

	cout << (dp[n][0][0] + dp[n][0][1] + MOD - 1) % MOD << endl;
	return 0;
}