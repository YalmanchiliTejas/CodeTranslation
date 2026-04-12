#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100, K = 3;

int dp[N + 1][K + 1], dq[N + 1][K + 1];

int main() {
	string s; cin >> s;
	int n = s.length();
	int k; cin >> k;
	dp[0][0] = 0;
	dq[0][0] = 1;
	for (int i = 0; i < n; i++) {
		int d = s[i] - '0';
		for (int j = 0; j <= k; j++) {
			dp[i + 1][j] += dp[i][j];
			if (j < k)
				dp[i + 1][j + 1] += dp[i][j] * 9;
			if (d == 0)
				dq[i + 1][j] += dq[i][j];
			else {
				dp[i + 1][j] += dq[i][j];
				if (j < k) {
					dp[i + 1][j + 1] += dq[i][j] * (d - 1);
					dq[i + 1][j + 1] += dq[i][j];
				}
			}
		}
	}
	cout << dp[n][k] + dq[n][k] << '\n';
	return 0;
}
