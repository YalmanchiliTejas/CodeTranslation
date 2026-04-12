#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int dp[3005][3005];

int dfs(std::vector<int>& a, int taro, int l, int r) {
	if (dp[l][r] != -1e15) return dp[l][r];
	if (l > r) {
		return 0;
	} 
	if (taro)
		return (dp[l][r] = max(dfs(a, !taro, l + 1, r) + a[l], dfs(a, !taro, l, r - 1) + a[r])); 
	return (dp[l][r] = min(dfs(a, !taro, l + 1, r) - a[l], dfs(a, !taro, l, r - 1) - a[r])); 
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	for (int i = 0; i < 3005; ++i) 
		for (int j = 0; j < 3005; ++j) 
			dp[i][j] = -1e15;
	int ans = dfs(a, 1, 0, n - 1);
	cout << ans;
}