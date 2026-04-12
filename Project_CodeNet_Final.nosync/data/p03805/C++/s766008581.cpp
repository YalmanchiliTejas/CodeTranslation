#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dfs(int now, vector<vector<int>>& adj_mat, bool* visited)
{
	bool all_visited = true;
	for(int i = 0; i < adj_mat.size(); i++){
		if(!visited[i]){
			all_visited = false;
			break;
		}
	}
	if(all_visited){
		// cout << "found one!" << endl;
		return 1;
	}
	int ways = 0;
	for(int i = 1; i < adj_mat.size(); i++){
		if(adj_mat[now][i] && !visited[i]){
			// cout << now << " to " << i << endl;
			visited[i] = true;
			ways += dfs(i, adj_mat, visited);
			visited[i] = false;
		}
	}
	return ways;
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> adj_mat(N, vector<int>(N));

	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		adj_mat[a - 1][b - 1] = 1;
		adj_mat[b - 1][a - 1] = 1;
	}

	bool visited[N];
	memset(visited, 0, sizeof(visited));
	visited[0] = true;
	int ways = dfs(0, adj_mat, visited);
	cout << ways << endl;
}