#include <iostream>

#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
	int n, k, m;
	cin >> n >> k >> m;
	vector<vector<int>> dp(2 * n + 1, vector<int>(1 << k, 0));
	dp[0][0] = 1;
	REP(i, 2 * n) {
		REP(j, 1 << k) {
			int b = __builtin_popcount(j);
			int pos = (i + b) / 2;
			if (b == k) continue;
			if ((j & (1 << (k - 1))) == 0) {
				int next = (j << 1) + 1;

				dp[i + 1][next] += dp[i][j];
				dp[i + 1][next] %= m;
			}
			if (b > 0) {
				int next = j;
				for (int a = k - 1; a >= 0; --a) {
					if (j & (1 << a)) {
						next ^= (1 << a);
						break;
					}
				}
				next <<= 1;
				dp[i + 1][next] += dp[i][j];
				dp[i + 1][next] %= m;
			}
		}
	}

	int ans = dp[2 * n][0];
	if (n == k) ans++;
	if (ans == m) ans = 0;
	cout << ans << endl;
}

