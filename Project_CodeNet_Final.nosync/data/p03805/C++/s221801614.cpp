#include<iostream>
#include<vector>
using namespace std;

bool graph[10][10];
bool visited[10], all_visited;


int dfs(int v,int n) {
	visited[1] = true;
	all_visited = true;
	for (int i = 1; i <= n; ++i) {
		if (visited[i] == false) {
			all_visited = false;
		}
	}
	if (all_visited)return 1;
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (graph[v][i] == false)continue;
		if (visited[i])continue;
		visited[i] =true;
		sum+=dfs(i, n);
		visited[i] = false;
	}
	return sum;
}

int main() {
	int n, m,a,b;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a>>b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	cout << dfs(1,n) << endl;
	return 0;
}