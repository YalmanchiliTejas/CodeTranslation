#include<iostream>

using namespace std;

static const int MAX = 8;
bool A[MAX][MAX];
bool visited[MAX];

int N, M;

int dfs(int v){
	bool all_visited = true;

	for(int i = 0; i < N; i++){
		if(visited[i] == false) all_visited = false;
	}

	if(all_visited) return 1;

	int ret = 0;

	for(int i = 0; i < N; i++){
		if(A[v][i] == false) continue;
		if(visited[i]) continue;

		visited[i] = true;
		ret += dfs(i);
		visited[i] = false;
	}

	return ret;
}

int main(){
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			A[i][j] = false;
		}
		visited[i] = false;
	}

	cin >> N >> M;
	int a, b;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		A[a - 1][b - 1] = A[b - 1][a - 1] = true;
	}

	visited[0] = true;
	cout << dfs(0) << endl;
	return 0;
}
