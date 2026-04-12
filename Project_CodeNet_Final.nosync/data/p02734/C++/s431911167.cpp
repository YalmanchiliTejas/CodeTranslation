#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;
using VL = vector<long long>;
using VVL = vector<VL>;

const int mod = 998244353;

int main() {
	int n, s;
	cin >> n >> s;

	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	VVL dp(n + 1, VL(s + 1, 0));

	for (int i = 0; i < n; i++) {
		dp[i][0]++;
		for (int j = 0; j <= s; j++) {
			if (dp[i][j] == 0) {
				continue;
			}

			dp[i+1][j] += dp[i][j];
			dp[i+1][j] %= mod;

			int nval = j + a[i];
			if (nval <= s) {
				dp[i+1][nval] += dp[i][j];
				dp[i+1][nval] %= mod;
			}
		}
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += dp[i][s];
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
