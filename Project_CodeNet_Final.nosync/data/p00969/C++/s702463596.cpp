#include <bits/stdc++.h>
using namespace std;

int n;
int v[5010];
map<int, int> mp;
int dp[5010][5010];
int dfs(int i, int j) {
	if(dp[i][j]) return dp[i][j];
	if(mp.count(v[i] - (v[j] - v[i]))) {
		int k = mp[v[i] - (v[j] - v[i])];
		int ret = dfs(k, i);
		return (dp[i][j] = max(dp[i][j], ret + 1));
	} else {
		return (dp[i][j] = 2);
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> v[i];
	sort(v, v + n);
	for(int i = 0; i < n; ++i) {
		mp[v[i]] = i;
	}
	int ans = 2;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			ans = max(ans, dfs(i, j));
		}	
	}
	cout << ans << '\n';
	return 0;
}

