#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve1(int n, vector<int>& ar) {
	vector<vector<ll>> dp(n + 2, vector<ll>(3, -1e18));
	dp[0][0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int skip = 0; skip < 3; ++skip) {
			if (i < n) {
				dp[i + 2][skip] = max(dp[i + 2][skip], dp[i][skip] + ar[i]);
			}
			if (skip < 2) {
				dp[i + 1][skip + 1] = max(dp[i + 1][skip + 1], dp[i][skip]);
			}
		}
	}
	cout << dp[n + 1][2] << endl;
}

void solve2(int n, vector<int>& ar) {
	vector<vector<ll>> dp(n + 2, vector<ll>(2, -1e18));
	dp[0][0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int skip = 0; skip < 2; ++skip) {
			if (i < n) {
				dp[i + 2][skip] = max(dp[i + 2][skip], dp[i][skip] + ar[i]);
			}
			if (skip < 1) {
				dp[i + 1][skip + 1] = max(dp[i + 1][skip + 1], dp[i][skip]);
			}
		}
	}
	cout << dp[n + 1][1] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> ar(n);
	for (int& v: ar) {
		cin >> v;
	}
	if (n & 1) {
		solve1(n, ar);
	} else {
		solve2(n, ar);
	}
}