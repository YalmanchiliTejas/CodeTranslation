#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MOD = (int)1e9 + 7;
string K;
int D;
int dig;
vector<vvi> dp;

void input_init(void) {
	cin >> K >> D;
	dig = K.length();
	dp.resize(dig + 1, vvi(D + 1, vi(2, 0)));
}

int solve(void) {
	dp[0][0][0] = 1;
	for (int i = 1; i <= dig; ++i) {
		for (int j = 0; j < D; ++j) {
			for (int k = 0; k < 10; ++k) {
				int now = (int)(K[i - 1] - '0');
				if (now > k) {
					dp[i][(j + k) % D][1] += (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
					dp[i][(j + k) % D][1] %= MOD;
				}
				else if (now == k) {
					dp[i][(j + k) % D][1] += dp[i - 1][j][1];
					dp[i][(j + k) % D][0] += dp[i - 1][j][0];
					dp[i][(j + k) % D][1] %= MOD;
					dp[i][(j + k) % D][0] %= MOD;
				}
				else {
					dp[i][(j + k) % D][1] += dp[i - 1][j][1];
					dp[i][(j + k) % D][1] %= MOD;
				}
			}
		}
	}
	int ret = dp[dig][0][0] + dp[dig][0][1] - 1;
	if (ret < 0)
		ret += MOD;
	ret %= MOD;
	return ret;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	input_init();
	int ans = solve();

	cout << ans << '\n';
	return 0;
}
