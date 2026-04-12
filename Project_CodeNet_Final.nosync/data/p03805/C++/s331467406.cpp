#include <bits/stdc++.h>
using namespace std;

int ans=0;
void dfs(int v, vector<vector<int>> &g, vector<bool> &visited) {
	visited[v] = true;

	bool visitedall=true;
	for (bool b : visited) {
		if (!b) {
			visitedall=false;
			break;
		}
	}
	if (visitedall) ans++;

	for (int i : g[v])
		if (!visited[i]) dfs(i,g,visited);

	visited[v] = false;
}

int main() {
	int n,m; cin>>n>>m;
	vector<vector<int>> g(n+1);
	for (int i=0; i<m; i++) {
		int a,b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<bool> visited(n+1);
	visited[0]=true;
	dfs(1,g,visited);
	cout << ans << endl;
	return 0;
}