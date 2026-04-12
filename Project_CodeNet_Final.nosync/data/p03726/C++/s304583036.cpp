/* in the name of allah */
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, dp[N], o[N];
bool vis[N];
vector<int> adj[N];

void readInput() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[--u].push_back(--v);
		adj[v].push_back(u);
	}
}

void dfs(int x) {
	vis[x] = true;
	for (auto v: adj[x])
		if (!vis[v])
			dfs(v), dp[x] += dp[v], o[x] += dp[v] % 2;
	dp[x]++;
	if (o[x] > 1) {
		cout << "First\n";
		exit(0);
	}
}

void solve() {
	if (n % 2) {
		cout << "First\n";
		return;
	}
	dfs(0);
	cout << "Second\n";
}

int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	readInput(), solve();
	return 0;
}