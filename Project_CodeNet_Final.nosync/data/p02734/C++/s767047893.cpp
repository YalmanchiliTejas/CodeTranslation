#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353

ll dp[3010][6010], A[3010];

int main() {
	for (int i = 0;i < 3010;i++) {
		for (int j = 0;j < 6010;j++) {
			dp[i][j] = 0;
		}
	}
	ll N, S;
	cin >> N >> S;
	for (int i = 0;i < N;i++) {
		cin >> A[i];
	}
	ll ans = 0;
	for (ll i = 0;i <= N;i++) {
		dp[i + 1][A[i]] += i + 1;
		dp[i + 1][0] += dp[i][0];

		dp[i + 1][A[i]] %= MOD;
		dp[i + 1][0] %= MOD;
		for (int j = 1;j < S;j++) {
			dp[i][j] %= MOD;
			dp[i + 1][j + A[i]] += dp[i][j];
			dp[i + 1][j] += dp[i][j];
			dp[i + 1][j + A[i]] %= MOD;
			dp[i + 1][j] %= MOD;
		}
		ans += dp[i][S] * (N - i + 1) % MOD;
		ans %= MOD;
	}
	cout << ans << endl;
}