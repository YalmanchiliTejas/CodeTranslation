#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <list>
#include <string>
using namespace std;

int ans = 0;

void dfs(int node, vector<vector<int> > adj, vector<int> visited){
	visited[node] = 1;
	for (int i = 0; i < visited.size(); i++){
		if (adj[node][i] && !visited[i]){
			dfs(i, adj, visited);
		}
	}
	int vsc = 0;
	for (int i = 0; i < visited.size(); i++)
		vsc += visited[i];
	if (vsc == visited.size())
		ans++;
}

int main()
{
	int i = 0, j = 0, p = 0, q = 0;
	ifstream fin("input.txt");
	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>(n));
	vector<int>visited(n);
	for (i = 0; i < m; i++){
		cin >> a >> b;
		a--;
		b--;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	dfs(0, adj, visited);
	cout << ans << endl;
	return 0;
}
