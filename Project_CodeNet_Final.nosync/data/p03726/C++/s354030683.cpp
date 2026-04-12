#include<bits/stdc++.h>
using namespace std;

const int N = 1000 * 100 + 10;
int sz[N], n;
vector<int> adj[N];

void dfs(int root, int par = 0) {
	int res = 0;
	for (auto u: adj[root])
		if (u ^ par) {
			dfs(u, root);
			sz[root] += sz[u];
			res += sz[u] % 2;
		}
	sz[root]++;
	res += (n - sz[root]) % 2;
	if (res > 1) {
		cout << "First\n";
		exit(0);
	}
}

int main() { 
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1, v, u; i < n; i++) {
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	if (n & 1)
		return cout << "First\n", 0;
	dfs(1);
	cout << "Second\n";
	return 0;
}
