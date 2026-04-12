#include <bits/stdc++.h>

using namespace std;

#define size(x) ((int) x.size())

const int MAXN = 1e5 + 5;

int n, u, v;

bool ans, mark[MAXN];

vector<int> adj[MAXN];

void dfs(int v, int par = 0) {
	for (auto u : adj[v]) {
		if (u != par) {
			dfs(u, v);
			if (!mark[u]) {
				if (!mark[v]) 
					mark[v] = mark[u] = true;
				else
					ans = true;
			}
		} 
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
//	cout << ans << " " << mark[0] << endl;
	if (ans || !mark[0])
		cout << "First" << endl;
	else
		cout << "Second" << endl;
	return 0;
}