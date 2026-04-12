#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[100010];

int dfs(int x, int pre = 0) {
	int cnt = 0;
	for (int i = 0; i < adj[x].size(); ++i) {
		int y = adj[x][i];
		if (y != pre)
			cnt += dfs(y, x);
	}
	return cnt < 2 ? cnt ^ 1 : cnt;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	puts(dfs(1) ? "First" : "Second");
}