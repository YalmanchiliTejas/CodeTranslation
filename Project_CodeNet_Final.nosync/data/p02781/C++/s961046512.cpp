#include <bits/stdc++.h>

//#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define int long long
using namespace std;
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int MB = 31;

void solve() {
	string s;
	cin >> s;
	vector<int> a(s.size());
	for (int i = 0; i < s.size(); i++) a[i] = s[i] - '0';

	int k;
	cin >> k;
	int n = s.size();
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(k + 1, vector<int>(n)));
	if (k) {
		dp[1][1][0] = 1;
		dp[0][1][0] = a[0] - 1;
	}
	dp[0][0][0] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[0][j][i] += dp[0][j][i - 1] + (j ? dp[0][j - 1][i - 1] * 9 + dp[1][j - 1][i - 1] * max(0LL, a[i] - 1) : 0) + (a[i] ? dp[1][j][i - 1] : 0);
			dp[1][j][i] = a[i] ? (j ? dp[1][j - 1][i - 1] : 0) : dp[1][j][i - 1];
		}
	}
	cout << dp[0][k][n - 1] + dp[1][k][n - 1];
}
signed main() {
	/*
	freopen("search.in", "r", stdin);
	freopen("search.out", "w", stdout);
	*/
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed;
	cout.precision(12);
	solve();
}