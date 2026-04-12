#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
ll dp[3005][3005][3];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i ++) cin >> a[i];
	dp[0][0][0] = 1;
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j <= k; j ++) {
			dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][0]) % MOD;
			dp[i + 1][j][1] = (dp[i + 1][j][1] + dp[i][j][0] + dp[i][j][1]) % MOD;
			dp[i + 1][j][2] = (dp[i + 1][j][2] + dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) % MOD;
			if(j + a[i] <= k) {
				dp[i + 1][j + a[i]][1] = (dp[i + 1][j + a[i]][1] + dp[i][j][0] + dp[i][j][1]) % MOD;
				dp[i + 1][j + a[i]][2] = (dp[i + 1][j + a[i]][2] + dp[i][j][0] + dp[i][j][1]) % MOD;
			}
		}
	}
	cout << dp[n][k][2];
	return 0;
}
