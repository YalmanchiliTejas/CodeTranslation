#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e4 + 1;
const int mod = 1e9 + 7;
int dp[maxn][100][3];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string k;
	cin >> k;
	int d;
	cin >> d;
	int n = k.size();
	for (int i = 1; i < (int)(k[0] - '0'); i++) {
		dp[1][i % d][0]++;
		dp[1][i % d][0] %= mod;
	}
	if (k[0] != '0') {
		dp[1][(k[0] - '0') % d][1]++;
		dp[1][(k[0] - '0') % d][1] %= mod;
	}
	for (int i = (int)(k[0] - '0') + 1; i <= 9; i++) {
		dp[1][i % d][2]++;
		dp[1][i % d][2] %= mod;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < d; j++) {
			int mx = k[i] - '0';
			for (int to = 0; to < mx; to++) {
				int kek = (j + to) % d;
				dp[i + 1][kek][0] += dp[i][j][0] + dp[i][j][1];
				dp[i + 1][kek][2] += dp[i][j][2];
				dp[i + 1][kek][0] %= mod;
				dp[i + 1][kek][2] %= mod;
			}
			dp[i + 1][(j + mx) % d][1] += dp[i][j][1];
			dp[i + 1][(j + mx) % d][1] %= mod;
			dp[i + 1][(j + mx) % d][0] += dp[i][j][0];
			dp[i + 1][(j + mx) % d][0] %= mod;
			dp[i + 1][(j + mx) % d][2] += dp[i][j][2];
			dp[i + 1][(j + mx) % d][2] %= mod;
			for (int to = mx + 1; to <= 9; to++) {
				int kek = (j + to) % d;
				dp[i + 1][kek][0] += dp[i][j][0];
				dp[i + 1][kek][2] += dp[i][j][1] + dp[i][j][2];
				dp[i + 1][kek][2] %= mod;
				dp[i + 1][kek][0] %= mod;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < n; i++) {
		ans += (dp[i][0][0] + dp[i][0][1] + dp[i][0][2]) % mod;
	}
	ans += (dp[n][0][0] + dp[n][0][1]) % mod;
	ans %= mod;
	cout << ans;
	return 0;
}