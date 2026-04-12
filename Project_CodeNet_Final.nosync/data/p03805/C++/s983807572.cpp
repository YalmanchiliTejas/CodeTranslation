#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> edge;

int dp[8][1 << 8];

int dfs(int now, int bits) {
	bits |= (1 << now);
	if (bits == (1 << n) - 1) {
		return 1;
	}
	if (~dp[now][bits]) return dp[now][bits];
	int res = 0;
	for (auto&& i : edge[now]) {
		if (bits & (1 << i)) {
			continue;
		}
		res += dfs(i, bits);
	}
	return dp[now][bits] = res;
}

int main() {
	cin >> n >> m;
	edge.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a - 1].push_back(b - 1);
		edge[b - 1].push_back(a - 1);
	}
	memset(dp, -1, sizeof dp);
	cout << dfs(0, 0) << "\n";
}