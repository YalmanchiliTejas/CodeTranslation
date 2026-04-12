#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void solve() {
		int n;
		cin >> n;
		vector<long long> a(n, 0);
		for (int i = 0; i < n; i++) cin >> a[i];
		int skip = (n % 2 == 0) ? 1 : 2;
		vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(skip + 1, vector<long long>(2, -(1LL << 60))));
		dp[0][0][0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= skip; j++) {
				// use
				dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][0] + a[i]);
				// skip
				if (j != skip) dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], dp[i][j][0]);
				// force skip(not counted)
				dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][1]);
			}
		}
		cout << max(max(dp[n][skip - 1][0], dp[n][skip - 1][1]), max(dp[n][skip][0], dp[n][skip][1])) << endl;

		return;
	};
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Solution solution;
	solution.solve();
	return 0;
}