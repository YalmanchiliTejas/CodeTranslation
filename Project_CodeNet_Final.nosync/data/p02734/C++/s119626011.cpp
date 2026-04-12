#include <iostream>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
ll a[3030], dp[3][3030][3030];

int main() {
	int n, s;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= s; ++j) {
			(dp[0][i + 1][j] += dp[0][i][j]) %= MOD;
			(dp[1][i + 1][j] += dp[0][i][j] + dp[1][i][j]) %= MOD;
			(dp[2][i + 1][j] += dp[0][i][j] + dp[1][i][j] + dp[2][i][j]) %= MOD;
			if (j + a[i] <= s) {
				(dp[1][i + 1][j + a[i]] += dp[0][i][j] + dp[1][i][j]) %= MOD;
				(dp[2][i + 1][j + a[i]] += dp[0][i][j] + dp[1][i][j]) %= MOD;
			}
		}
	}
	printf("%d", dp[2][n][s]);
	return 0;
}