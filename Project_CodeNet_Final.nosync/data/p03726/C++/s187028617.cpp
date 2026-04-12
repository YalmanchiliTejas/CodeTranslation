/* Èå äÇã Çæ */
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100 * 1000 + 5;
int n;
vector<int> adj[MAX_N];

void read_input() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
}

int dfs(int v, int pr = -1) {
	int res = 1, cnt = 0;
	for (int u: adj[v])
		if (u != pr) {
			int sz = dfs(u, v);
			res += sz;
			cnt += sz & 1;
		}
	if (cnt > 1 || n & 1) {
		cout << "First" << endl;
		exit(0);
	}
	return res;
}

void solve() {
	dfs(0);
	cout << "Second" << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	read_input();
	solve();
}