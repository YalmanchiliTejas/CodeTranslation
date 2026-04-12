#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define int long long
using namespace std;
const int INF = 2e16;
const int MOD = 1e9 + 7;
const int MB = 20;
const int K = 500;
const int maxN = 2e4 + 1;

void solve() {
	string s;
	int d;
	cin >> s >> d;
	int len = s.size();
	vector<int> a(len);
	for (int i = 0; i < len; i++) a[i] = s[i] - '0';
	vector<vector<int>> dp(2, vector<int>(d));
	
	for (int i = 0; i < a[0]; i++) dp[0][i % d]++;
	dp[1][a[0] % d] = 1;

	for (int i = 1; i < len; i++) {
		vector<vector<int>> dp1(2, vector<int>(d));
		for (int j = 0; j < d; j++) {
			for (int c = 0; c < 10; c++) {
				dp1[0][j] = (dp1[0][j] + dp[0][(j - c % d + d) % d] + (c < a[i] ? dp[1][(j - c % d + d) % d] : 0)) % MOD;
				if (c == a[i]) dp1[1][j] = dp[1][(j - c % d + d) % d];
			}
		}
		swap(dp, dp1);
	}
	cout << ((dp[0][0] + dp[1][0]) % MOD - 1 + MOD) % MOD;
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