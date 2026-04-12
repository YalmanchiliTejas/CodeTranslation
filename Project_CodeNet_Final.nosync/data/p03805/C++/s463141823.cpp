#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int x, int n, bool visited[nmax]) {
	bool all_visited = true;
	rep(i,n) if (!visited[i]) all_visited = false;

	if (all_visited) return 1;
	
	int ret = 0;
	rep(i,n) {
		if (!graph[x][i]) continue;
		if (visited[i]) continue;

		visited[i] = true;
		ret += dfs(i,n,visited);
		visited[i] = false;
	}
	return ret;
}

int main() {
	int n,m;
	cin >> n >> m;
	rep(i,n) rep(j,n) graph[i][j] = false;
	rep(i,m) {
		int a,b;
		cin >> a >> b;
		a--;b--;
		graph[a][b] = graph[b][a] = true;
	}

	bool visited[nmax];
	rep(i,n) visited[i] = false;

	visited[0] = true;
	cout << dfs(0,n,visited) << endl;
	return 0;
}
