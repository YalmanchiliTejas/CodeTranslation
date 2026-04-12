/* In the name of Allah */
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int n, sz[N];

void dfs(int u, int par) {
	sz[u] = 1;
	int cnt = 0;
	for (auto v: adj[u])
		if (v ^ par) {
			dfs(v, u);
			sz[u] += sz[v];
			cnt += sz[v] & 1;
		}
	if (cnt > 1) {
		cout << "First\n";
		exit(0);
	}
}

inline void readInput() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;

		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

inline void solve() {
	dfs(0, 0);
	cout << (n & 1? "First\n": "Second\n");
}

int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	readInput(), solve();
	return 0;
}