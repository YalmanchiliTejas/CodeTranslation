#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define int long long
#define mod 1000000007

int dp[3000][3000];

int solve1(int* a, int l, int r) {
	if (l > r)return 0;
	if (dp[l][r] != -1)return dp[l][r];
	if (l == r)return dp[l][r] = a[l];
	dp[l][r] = max(a[l] - solve1(a, l + 1, r) , a[r] - solve1(a, l, r - 1));
	return dp[l][r];
}

void solve() {
	int n;
	cin >> n;
	int a[n];
	int i;
	for (i = 0; i < n; i++)cin >> a[i];

	memset(dp, -1, sizeof(dp));
	int j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i > j)dp[i][j] = 0;
			else if (i == j)dp[i][j] = a[i];
		}
	}

	int len = solve1(a, 0, n - 1);
	cout << len << endl;

	return;
}


int32_t main() {
	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	solve();
	return 0;
}