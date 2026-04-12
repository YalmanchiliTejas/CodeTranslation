#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;

const int Nmax = 8;
bool graph[Nmax][Nmax];

int dfs(int v,int N, bool visited[Nmax]) {
	bool all_visited = true;

	for (int i = 0; i < N; i++) {
		if (visited[i] == false) {
			all_visited = false;
		}
	}

	if (all_visited) return 1;

	int ret = 0;

	for (int i = 0; i < N; i++) {
		if (graph[v][i] == false || visited[i]) continue;
		visited[i] = true;
		ret += dfs(i, N, visited);
		visited[i] = false;
	}

	return ret;
}

int main() {
	int N, M, a, b;
	cin >> N >> M;
	bool visited[Nmax];

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a-1][b-1] = graph[b-1][a-1] = true;
		visited[i] = false;
	}
	visited[0] = true;

	cout << dfs(0, N, visited) << endl;
	return 0;
}