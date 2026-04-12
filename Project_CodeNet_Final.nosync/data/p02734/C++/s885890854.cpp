#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <deque>
using namespace std;

long long dp[3001][3001][3];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, s;
	cin >> n >> s;
	vector <int> v;
	v.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			(dp[i][j][0] += dp[i - 1][j][0]) %= 998244353;
			(dp[i][j][1] += dp[i - 1][j][0] + dp[i - 1][j][1]) %= 998244353;
			(dp[i][j][2] += dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2]) %= 998244353;
			if (j + v[i - 1] <= s) {
				(dp[i][j + v[i - 1]][1] += dp[i - 1][j][0] + dp[i - 1][j][1]) %= 998244353;
				(dp[i][j + v[i - 1]][2] += dp[i - 1][j][0] + dp[i - 1][j][1]) %= 998244353;
			}
		}
	}
	cout << dp[n][s][2] << endl;
}