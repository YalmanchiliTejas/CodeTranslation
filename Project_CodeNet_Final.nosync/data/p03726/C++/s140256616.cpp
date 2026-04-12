#include <bits/stdc++.h>
using namespace std;

const int MN = 101234;
vector <int> adj[MN];

int dfs(int v, int p) {
	cerr << v << ' ' << p << endl;
	int cnt[3] = {};
	for (int u: adj[v]) 
		if (u != p)
			cnt[dfs(u, v)]++;
	if (cnt[2])
		return 2;
	if (cnt[1] > 1)
		return 2;
	return 1 - cnt[1];
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++) 
		if (adj[i].size() == 1) {
			if (dfs(i, i))
				cout << "First";
			else
				cout << "Second";
			return 0;
		}
}