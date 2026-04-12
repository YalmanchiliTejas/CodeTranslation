#include <bits/stdc++.h>
using namespace std;
using ll = long long;
enum { MAXN = 8 };
int n, m;
vector<int> adj[MAXN+5];
vector<bool> vis(MAXN+5, false);

int dfs(int u) {
	bool av = true;
	for (int i = 1; i <= n; i++) {
		av &= vis[i];
	}
	if (av) {
		return 1;
	}
	int ret = 0;
	for (auto ui : adj[u]) {
		if (!vis[ui]) {
			vis[ui] = true;
			ret += dfs(ui);
			vis[ui] = false;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vis[1] = true;
	cout << dfs(1) << endl;
	return 0;
}