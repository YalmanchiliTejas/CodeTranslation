#include <iostream>
#include <set>
using namespace std;

const int N = 100 * 1000 + 5;

set <pair <int, int> > s;
set <int> adj[N];
int h[N];
int par[N];
bool mark2[N];
void dfs(int v) {
	s.insert({-h[v], v});
	for (auto u : adj[v]) {
		if (u != par[v]) {
			par[u] = v;
			h[u] = h[v] + 1;
			dfs(u);
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	if (n % 2 == 1) {
		cout << "First";
	}
	else {
		dfs(1);
		while (s.size()) {
			pair <int, int> p = *s.begin();
			int v = p.second, u = par[v];
		//	cout << v << " " << u << endl;
			s.erase({-h[v], v});
			s.erase({-h[u], u});
			if (mark2[u] == true) {
				cout << "First";
				return 0;
			}
			for (auto w : adj[u]) {
				adj[w].erase(u);
			}
			adj[u].erase(v);
			mark2[v] = true;
			mark2[u] = true;
		}
		cout << "Second";
	}
	return 0;
}
