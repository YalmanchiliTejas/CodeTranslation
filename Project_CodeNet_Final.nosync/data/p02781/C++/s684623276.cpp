#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

signed main() {
	string N; cin >> N;
	int K; cin >> K;
	vector<vector<vector<ll>>> dp(
		N.length() + 1, vector<vector<ll>>(
			K + 1, vector<ll>(2, 0)
			)
	);
	dp[0][0][0] = 1;
	for (int i = 1; i <= N.length(); ++i) {
		int d = N[i - 1] - '0';
		for (int j = 0; j <= K; ++j) {
			if (j < K)
				dp[i][j + 1][1] += 9 * dp[i - 1][j][1];
			dp[i][j][1] += dp[i - 1][j][1];
			if (d) {
				if (j < K) {
					dp[i][j + 1][1] += (d - 1LL) * dp[i - 1][j][0];
					dp[i][j + 1][0] += dp[i - 1][j][0];
				}
				dp[i][j][1] += dp[i - 1][j][0];
			}
			else
				dp[i][j][0] += dp[i - 1][j][0];
		}
	}
	cout << (dp[N.length()][K][0] + dp[N.length()][K][1]) << endl;
	return 0;
}