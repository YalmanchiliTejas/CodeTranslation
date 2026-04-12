#include <bits/stdc++.h>
using namespace std;
const int MAX = (1e5)+1;

int n, m, par[MAX], lvl[MAX];
set<int> g[MAX];
queue<int> leaves;
bool mark[MAX];
void dfs(int u) {
	if(g[u].size() == 1) leaves.push(u);
	for(int v: g[u]) if(v != par[u]) {
		par[v] = u;
		lvl[v] = lvl[u]+1;
		dfs(v);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	if(n == 1) cout << "First", exit(0);
	else if(n == 2) cout << "Second", exit(0);
	int root = 1;
	while(g[root].size() == 1) root++;
	dfs(root);
	while(!leaves.empty()) {
		int v = leaves.front();
		leaves.pop();
		if(!g[v].count(par[v])) cout << "First", exit(0);
		mark[v] = mark[par[v]] = true;
		for(int x: g[par[v]]) g[x].erase(par[v]);
		if(g[par[par[v]]].size() == 1 && lvl[*g[par[par[v]]].begin()] < lvl[par[par[v]]]) leaves.push(par[par[v]]);
	}
	for(int i = 1; i <= n; i++) if(!mark[i]) cout << "First", exit(0);
	cout << "Second";
}
