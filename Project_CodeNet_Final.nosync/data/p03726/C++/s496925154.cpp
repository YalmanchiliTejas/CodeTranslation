/* be name Khoda */
#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1001;
int n, sz[N];
bool ok;
vector<int> adj[N];


void dfs(int u, int par = -1) {
	sz[u] = 1;
	int cnt = 0;
	for (auto v: adj[u])
		if (par != v) {
			dfs(v, u);
			sz[u] += sz[v];
			if (sz[v] % 2)
				cnt++;
		}
	if (cnt >= 2)
		ok = true;

}

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (n % 2) {
		cout << "First\n";
		return 0;
	}
	dfs(0);
	if (ok) 
		cout << "First\n";
	else
		cout << "Second\n";
}