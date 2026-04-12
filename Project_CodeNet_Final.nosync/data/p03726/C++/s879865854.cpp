//besmellah
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 58;
int sz[maxn];
vector <int> adj[maxn];

bool dfs(int v, int p = -1) {
	bool f = 1;
	int t = 0;
	sz[v] = 1;
	for (auto u: adj[v]) {
		if (u != p) {
			f = dfs(u, v) & f;
			sz[v] += sz[u];
			if (sz[u] % 2) t++;
		}
	}
	return f && (t <= 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		v--;
		u--;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	if (dfs(0) && n % 2 == 0) cout << "Second";
	else cout << "First";
}
