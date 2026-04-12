#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9 + 7, MOD = 1e9 + 7;
const long long LINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool Graph[8][8];

int dfs(int v, int n, bool visited[8]) {
	bool All_Visited = true;
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			All_Visited = false;
		}
	}
	if (All_Visited) {
		return 1;
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (Graph[v][i] == false) {
			continue;
		}
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		ret += dfs(i, n, visited);
		visited[i] = false;
	}
	return ret;
}

signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		Graph[a][b] = Graph[b][a] = true;
	}
	bool visited[8] = {};
	visited[0] = true;
	cout << dfs(0, n, visited) << endl;
	return 0;
}