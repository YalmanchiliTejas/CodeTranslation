#include <bits/stdc++.h>
using namespace std;

int64_t solve(int64_t n, vector<int64_t> &as, vector<vector<int64_t>> &dp, int i, int j)
{
	if (dp[i][j] != -(1LL << 60))
	{
		return dp[i][j];
	}
	if (i + j == n)
	{
		return 0;
	}
	return dp[i][j] = max(as[i] - solve(n, as, dp, i + 1, j), as[n - j - 1] - solve(n, as, dp, i, j + 1));
}

int main()
{
	int64_t n;
	cin >> n;
	vector<int64_t> as(n);
	for (auto &a : as)
	{
		cin >> a;
	}
	vector<vector<int64_t>> dp(n + 1, vector<int64_t>(n + 1, -(1LL << 60)));
	cout << solve(n, as, dp, 0, 0) << endl;
	return 0;
}