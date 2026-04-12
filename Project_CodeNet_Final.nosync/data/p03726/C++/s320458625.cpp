#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int dp[N];
vector <int> adj[N];

void dfs (int v, int p = -1) {
	int cnt = 0;
	for (auto u : adj[v]) {
		if(u == p) 	continue;
		dfs(u, v);
		dp[v] += dp[u];
		cnt += dp[u] % 2;
	}
	dp[v]++;
	if(cnt >= 2)	{
		cout << "First\n";
		exit(0);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		adj[v].push_back(u), adj[u].push_back(v);
	}
	if(n % 2 == 1) {
		cout << "First\n";
		return 0;
	}
	dfs(0);
	cout << "Second\n";
}