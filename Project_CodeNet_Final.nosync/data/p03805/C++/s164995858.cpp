#include <bits/stdc++.h>
using namespace std;
const int N = 8;

vector<int>adjList[70];
int n, m;

int dfs (bitset<N> visited, int node) {
	if ((int)visited.count() == n)
		return 1;
	int path = 0;
	for (auto i : adjList[node]) {
		if (!visited[i-1]) {
			visited[i-1] = true;
			path += dfs(visited, i);
			visited[i-1] = false;
		}
	}
	return path;
}


int main ()
{
	cin >> n >> m;
	for (int i = 0; i < m ; i ++) {
		int x,y ;
		cin >> x >> y;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}
	bitset<N>bs(1);
	cout << dfs(bs, 1) << endl;
  	return 0;
}
