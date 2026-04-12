// https://atcoder.jp/contests/dp/tasks/dp_l

#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <limits>

using namespace std;

void helper(const vector<long long>& points, vector<vector<vector<long long>>>& dp, int l, int r) {
	if (l > r) return;
	if (dp[l][r][0] != numeric_limits<long long>::min()) return;

	helper(points, dp, l + 1, r);
	helper(points, dp, l, r - 1);

	if (l == r) {
		dp[l][r][0] = points[l];
		dp[l][r][1] = -points[l];
	} else {
		dp[l][r][0] = max(dp[l][r - 1][1] + points[r], dp[l + 1][r][1] + points[l]);
		dp[l][r][1] = min(dp[l][r - 1][0] - points[r], dp[l + 1][r][0] - points[l]);
	}
}

int main (int argc, char* argv[]) {
	int n;
	cin >> n;

	vector<long long> points(n);
	for (int i = 0; i < n; i++) {
		cin >> points[i];
	}

	vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, numeric_limits<long long>::min())));
	helper(points, dp, 0, n - 1);

	cout << dp[0][n - 1][0] << endl;
}
