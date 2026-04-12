#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define mod 1000000007
#define int long long

int dp[3001][3001][2];

int game(int i, int j, int k, vector<int> &a) {
	int n = a.size();
	if (i >= n || j >= n || i < 0 || j < 0)return 0;
	if (i > j)return dp[i][j][k] = 0;
	if (dp[i][j][k] != -1)return dp[i][j][k];

	dp[i][j][0] = max(a[i] + game(i + 1, j, 1, a), a[j] + game(i, j - 1, 1, a));
	dp[i][j][1] = min(game(i + 1, j, 0, a), game(i, j - 1, 0, a));

	return dp[i][j][k];
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int i, j, k;
	for (i = 0; i < n; i++)cin >> a[i];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < 2; k++)dp[i][j][k] = -1;
		}
	}

	int sum = 0;
	for (i = 0; i < n; i++) {
		sum += a[i];
	}

	int x = game(0, n - 1, 0, a);
	int y = sum - x;
	cout << x - y << endl;

	return;
}

int32_t main() {

	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while (t--)solve();
	return 0;
}