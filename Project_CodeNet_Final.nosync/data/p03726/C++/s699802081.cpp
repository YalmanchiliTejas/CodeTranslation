#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool t[N];
vector<vector<int> > g;

void dfs(int u, int p) {

	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v != p) {
			dfs(v, u);
		}
	}
	if (p >= 0 && !t[u] && !t[p]) {
		t[u] = t[p] = 1;
	}
}

int main() {

//	freopen("readin.txt", "r", stdin);

	int n;
	scanf("%d", &n);
	g.resize(n);
	for (int i = 0, a, b; i < n - 1; i++) {
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, -1);
	for (int i = 0; i < n; i++) {
		if (!t[i]) {
			puts("First");
			return 0;
		}
	}
	puts("Second");
	return 0;
}
