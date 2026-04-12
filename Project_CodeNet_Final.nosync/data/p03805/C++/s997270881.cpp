
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
bool graph[8][8];
int dfs(int v, int N, bool visited[8]) {
	bool all_visited = true;
	int i, j, k, res;
	res = 0;
	for (i = 0; i < N; i++) {
		if (visited[i] == false) {
			all_visited = false;
		}
	}
	if (all_visited) {
		return 1;
	}
	for (i = 0; i < N; i++) {
		if (graph[v][i]==false) continue;
		if (visited[i]) continue;
		visited[i] = true;
		res += dfs(i, N, visited);
		visited[i] = false;
	}
	return res;
}
int main()
{
	int i,N,M,j,k,v,a,b;
	bool visited[8];
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		visited[i] = false;
	}
	
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
	}
	visited[0] = true;
	cout << dfs(0, N, visited) << endl;
    return 0;
}

