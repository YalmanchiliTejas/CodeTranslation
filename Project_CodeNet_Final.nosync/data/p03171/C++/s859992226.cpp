#include "bits/stdc++.h"
using namespace std;
#define Fast_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
vector<vector<int>> dp;
int solve(vector<int> &a, int i, int j) {
	if (i > j) {
		return 0;
	}
	if (i == j) {
		return a[i];
	}

	if (~dp[i][j])
		return dp[i][j];

	int c1 = a[i] + min(solve(a, i + 1, j - 1), solve(a, i + 2, j));
	int c2 = a[j] + min(solve(a, i + 1, j - 1), solve(a, i, j - 2));

	return dp[i][j] = max(c1, c2);
}

int32_t main() {
	Fast_IO
	int n; cin >> n;
	dp = vector<vector<int>>(n, vector<int>(n, -1));

	vector<int> a(n);
	for (auto &i : a)
		cin >> i;

	cout << 2 * solve(a, 0, n - 1) - accumulate(a.begin(), a.end(), 0LL);
}