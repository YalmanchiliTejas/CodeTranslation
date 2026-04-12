#include <iostream>
using namespace std;

using ll = long long;
constexpr ll MOD = 998244353;

ll a[3030], dp[3030][3][3030];

int main() {
	int n, s;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= s; ++j) {
			(dp[i + 1][0][j] += dp[i][0][j]) %= MOD;
			(dp[i + 1][1][j] += dp[i][0][j] + dp[i][1][j]) %= MOD;
			(dp[i + 1][2][j] += dp[i][0][j] + dp[i][1][j] + dp[i][2][j]) %= MOD;
          if (j + a[i] <= s) {
			(dp[i + 1][1][j + a[i]] += dp[i][0][j] + dp[i][1][j]) %= MOD;
			(dp[i + 1][2][j + a[i]] += dp[i][0][j] + dp[i][1][j]) %= MOD;
          }
		}
	}
	printf("%d", dp[n][2][s]);
	return 0;
}
