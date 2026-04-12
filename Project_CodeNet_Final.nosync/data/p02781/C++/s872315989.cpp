#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	string N;
	cin >> N;
	int K;
	cin >> K;

	N = "x" + N;
	int n = N.size();
	Int dp[110][5][2] = { 0 };
	dp[0][0][1] = 1;
	for (int i = 1; i < n; ++i) {
		int x = N[i] - '0';
		// j := 各桁の値
		for (int j = 0; j < 10; ++j) {
			// k := 0でない数字の数
			for (int k = 0; k <= K + 1; ++k) {
				if (j < x) {
					if (j == 0) {
						dp[i][k][0] += dp[i-1][k][0] + dp[i-1][k][1];
					} else if (k > 0) {
						dp[i][k][0] += dp[i-1][k-1][0] + dp[i-1][k-1][1];
					}
				}
				if (j == x) {
					if (j == 0) {
						dp[i][k][0] += dp[i-1][k][0];
						dp[i][k][1] += dp[i-1][k][1];
					} else if (k > 0) {
						dp[i][k][0] += dp[i-1][k-1][0];
						dp[i][k][1] += dp[i-1][k-1][1];
					}
				}
				if (j > x && k > 0) {
					dp[i][k][0] += dp[i-1][k-1][0];
				}
			}
		}
	}

	Int ans = dp[n - 1][K][0] + dp[n - 1][K][1];
	cout << ans << endl;

	return 0;
}
