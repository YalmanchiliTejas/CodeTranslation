#include <vector>
#include <iostream>
using namespace std;
bool vis[10];
int n, m, ans;
vector<int> g[10];
void dfs(int u, int cnt) {
	if (cnt == n) {
		ans++;return;
	}
	vis[u] = true;
	for (int i = 0; i < (int)g[u].size(); i++) {
		int v = g[u][i];
		if (!vis[v]) dfs(v, cnt+1);
	}
	vis[u] = false;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	cout << ans << endl;
	return 0;
}