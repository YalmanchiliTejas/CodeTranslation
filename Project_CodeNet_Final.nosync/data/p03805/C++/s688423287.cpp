#include <bits/stdc++.h>

using namespace std;

vector <int> g[10];

int visited[10];
int n, ans = 0;

void dfs(int u) {
	visited[u] = 1;
	bool todo = true;
	for (int i = 0; i < n; ++i) {
		if (visited[i] == 0) {
			todo = false;
			break;
		}
	}
	if (todo) {
		ans++;
		visited[u] = 0;
		return;
	}
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (visited[v] == 0) {
			dfs(v);	
		}	
	}
	visited[u] = 0;
}

int main() {
	for (int i = 0; i < 10; i++) {
		visited[i] = 0;
		g[i].clear();
	}	
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x - 1].push_back(y - 1);
		g[y - 1].push_back(x - 1);
	}
	dfs(0);
	printf("%d\n", ans);
	return 0;
}