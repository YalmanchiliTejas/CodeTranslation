#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> gr[N];
int dp[N][3];
void dfs(int v, int par) {
	for (auto u : gr[v]) 
		if (u != par)
			dfs(u, v);
	int ps = 0, z = 0;
	for (auto u : gr[v]) {
		if (u != par) {
			ps += dp[u][1];
			if (dp[u][1] == dp[u][0])
				z = 1;
		}
	}
	dp[v][0] = ps, dp[v][1] = ps + z;
	return;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		gr[x].push_back(y), gr[y].push_back(x);
	}
	dfs(0, 0);
	if (dp[0][1] != (n + 1) / 2)
		cout << "First";
	else
		cout << "Second";
	return 0;
}
