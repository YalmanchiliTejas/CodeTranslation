#include <bits/stdc++.h>

using namespace std;

const int N = 10;

vector <int> g[N];
int visited[N];
int n;

int dfs(int u) {
	bool fail = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) fail = 1;		
	}
	if (!fail) return 1;
	int ans = 0;
	for (int i = 0; i < (int)g[u].size(); i++) {
		int v = g[u][i];
		if (!visited[v]) {
			visited[v] = 1;
			ans += dfs(v);
			visited[v] = 0;
		}
	}
	return ans;
}

int main() {
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x - 1].push_back(y - 1);
		g[y - 1].push_back(x - 1);			
	}
	visited[0] = 1;
	int ans = dfs(0);
	printf("%d\n", ans);
	return 0;
}