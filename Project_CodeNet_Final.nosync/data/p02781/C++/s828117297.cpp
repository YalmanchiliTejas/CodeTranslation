#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	string N;
	cin >> N;
	int K;
	cin >> K;

	int n = N.size();
	Int dp[110][5][2] = { 0 };
	dp[0][0][1] = 1;
	for (int i = 0; i < n; ++i) {
		int x = N[i] - '0';
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k <= K; ++k) {
				if (j == 0) {
					dp[i+1][k][0] += dp[i][k][0];
					if (j < x) {
						dp[i+1][k][0] += dp[i][k][1];
					}
					if (j == x) {
						dp[i+1][k][1] += dp[i][k][1];
					}
				} else {
					dp[i+1][k+1][0] += dp[i][k][0];
					if (j < x) {
						dp[i+1][k+1][0] += dp[i][k][1];
					}
					if (j == x) {
						dp[i+1][k+1][1] += dp[i][k][1];
					}
				}
			}
		}
	}
	Int ans = dp[n][K][0] + dp[n][K][1];
	cout << ans << endl;

	return 0;
}
