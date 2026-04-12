#include <iostream>

using namespace std;

typedef long long ll;

ll dp[3001][3001][3];

int main() {
	ll n, s, * a,m= 998244353;
	cin >> n >> s;
	a = new ll[n];
	for (int i = 0; i < n; i++)cin >> a[i];
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= s; j++) {
			dp[i + 1][j][0] += dp[i][j][0];
			dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1];
			if(j+a[i]<=s)dp[i + 1][j + a[i]][1] += dp[i][j][0] + dp[i][j][1];
			dp[i + 1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
			if(j+a[i]<=s)dp[i + 1][j + a[i]][2] += dp[i][j][0] + dp[i][j][1];
			dp[i + 1][j][0] %= m;
			dp[i + 1][j][1] %= m;
			dp[i + 1][j][2] %= m;

		}
	}
	cout << dp[n][s][2] << endl;
}
