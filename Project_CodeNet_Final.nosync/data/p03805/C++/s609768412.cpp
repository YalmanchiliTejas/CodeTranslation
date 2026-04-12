#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int NMAX = 8;
bool graph[NMAX][NMAX];

int dfs(int v,int N,bool visited[NMAX]);
int main(){
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = true;
		graph[b - 1][a - 1] = true;
	}

	bool visited[NMAX];
	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
	visited[0] = true;

	cout << dfs(0,N,visited) << endl;

	return 0;
}

int dfs(int v,int N,bool visited[NMAX]) {

	//cout << "now: " << v+1 << endl;
	bool all_visited = true;
	for (int i = 0; i < N; i++) {
		if (visited[i] == false) {
			all_visited = false;
		}
	}
	if (all_visited) {
		//cout << "return all_visited" << endl;
		return 1;
	}

	int ret = 0;

	for (int i = 0; i < N; i++) {
		//cout << "v, i: " << v << ", " << i << ": " << graph[v][i] << ", " << visited[i] << endl;
		if (graph[v][i] && !visited[i]) {
			visited[i] = true;
			ret += dfs(i, N, visited);
			visited[i] = false;
		}
	}
	//cout << "return ret" << endl;
	return ret;
}
