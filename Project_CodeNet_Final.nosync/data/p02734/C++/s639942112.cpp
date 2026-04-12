#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

const int64_t M = 998244353;
int64_t dfs(vector<vector<int64_t>> &dp, vector<vector<int64_t>> &dp2, const vector<int64_t> &v, const int64_t &n, int64_t i, int64_t s);

int64_t dfs2(vector<vector<int64_t>> &dp, vector<vector<int64_t>> &dp2, const vector<int64_t> &v, const int64_t &n, int64_t i, int64_t t) {
	if (dp2[i][t] != -1) return dp2[i][t];
	if (i == 0) return dp2[i][t] = dfs(dp, dp2, v, n, i, t);
	return dp2[i][t] = (dfs(dp, dp2, v, n, i, t) + dfs2(dp, dp2, v, n, i-1, t)) % M;
}

int64_t dfs(vector<vector<int64_t>> &dp, vector<vector<int64_t>> &dp2, const vector<int64_t> &v, const int64_t &n, int64_t i, int64_t s) {
	if (dp[i][s] != -1) return dp[i][s];
	if (v[i] > s) return dp[i][s] = 0;
	if (v[i] == s) return dp[i][s] = i+1;
	int64_t t = s - v[i];
	if (i == 0) return dp[i][s] = 0;
	return dp[i][s] = dfs2(dp, dp2, v, n, i-1, t);
}

int main() {
	ios_base::sync_with_stdio(false);
	int64_t n, sum;
	cin>>n>>sum;
	vector<int64_t> v(n, 0);
	for (int64_t i = 0; i < n; i++) cin>>v[i];
	
	vector<vector<int64_t>> dp(n, vector<int64_t>(sum+1, -1));
	vector<vector<int64_t>> dp2(n, vector<int64_t>(sum+1, -1));

	int64_t res = 0;
	for (int64_t i = 0; i < n; i++) {
		res = (res + dfs(dp, dp2, v, n, i, sum) * (n-i) % M) %M;
	}

	cout<<res<<endl;
	return 0;
}