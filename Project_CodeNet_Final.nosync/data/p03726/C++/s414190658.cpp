# include <bits/stdc++.h>

using namespace std;
const int maxn = 100010;
vector<int> g[maxn];

int dfs(int u,int par) {
	int cnt = 0;
	for(auto v: g[u]) if(v != par) cnt += dfs(v, u);
	if(cnt == 0) return 1;
	if(cnt == 1) return 0;
	return 100;
}

int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	puts(dfs(1, 1) == 0 ? "Second" : "First");
	return 0;
}
