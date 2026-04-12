//In The Name Of Allah
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())
#define double long double 
#define fi first
#define se second
#define pii pair<int, int>

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<int>> dp(n, vector<int> (n, INT64_MIN));
	for (int i = 0; i < n; i++) {
		dp[i][i] = a[i];
	}
	for (int l = 2; l <= n; l++) {
		for (int i = 0, j = l - 1; j < n; i++, j++) {
			dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
		}
	}
	cout << dp[0][n - 1] << "\n";
}

