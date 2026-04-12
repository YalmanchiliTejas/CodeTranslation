//BE NAM NAMI HAGH
#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int sz[MAXN];
int n;

void input();
void dfs(int, int);
void solve();

int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	input();
	solve();
	return 0;
}

void input() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void dfs(int u, int par) {
	int cnt = 0;
	sz[u] = 1;
	for (auto v: adj[u]) {
		if (v == par) continue;
		dfs(v, u);
		sz[u] += sz[v];
		cnt += (sz[v] & 1);
	}
	if (cnt > 1) {
		cout << "First" << endl;
		exit(0);
	}
}

void solve() {
	if (n & 1) {
		cout << "First" << endl;
		return;
	}
	dfs(0, -1);
	cout << "Second" << endl;
}
