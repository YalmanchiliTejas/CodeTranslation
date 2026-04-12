#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
vector<int> adj[N];
bool use[N], win;
int n;
void dfs(int v, int p) {
	for (auto u : adj[v]) {
		if (u == p)
			continue;
		dfs(u, v);
		if (!use[u]) {
			if (!use[v]) {
				use[u] = true;
				use[v] = true;
			}
			else
				win = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		adj[--v].push_back(--u);
		adj[u].push_back(v);	
	}
	dfs(0, 0);
	return cout << ((win || !use[0]) ? "First" : "Second"), 0;
}