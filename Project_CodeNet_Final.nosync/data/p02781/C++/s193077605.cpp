#include <bits/stdc++.h>
using namespace std;

int n, k, dp[5][105][3];
char s[105];

int dfs(int use, int m, int lim) {
	if (use > k) return 0;
	if (m > n) return use == k;
	if (dp[use][m][lim] != -1) return dp[use][m][lim];
	int ans = 0;
	int up = lim == 1 ? s[m] - '0' : 9;
	for (int i = 0; i <= up; i++)
		ans += dfs(use + (i != 0), m + 1, lim and i == up);
	return dp[use][m][lim] = ans;
}

int main() {
	cin >> (s + 1) >> k;
	n = strlen(s + 1);
	memset(dp, -1, sizeof dp);
	cout << dfs(0, 1, 1);
}