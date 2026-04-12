#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> pi;

int N, M;
vector<int> G[10];
int ans = 0;
vector<bool> visited(10, false);

void dfs(int v){
	bool allvisited = true;
	for(int i = 0; i < N; ++i)
		if(visited[i] == false) allvisited = false;

	if(allvisited){
		ans++;
		return;
	}else{
		for(int i = 0; i < G[v].size(); ++i){
			if(visited[G[v][i]] == false){
				visited[G[v][i]] = true;
				dfs(G[v][i]);
				visited[G[v][i]] = false;
			}
		}
		return;
	}
}

int main(){
	cin >> N >> M;
	for(int i = 0; i < M; ++i){
		int from, to;
		cin >> from >> to; from--; to--;
		G[from].push_back(to);
		G[to].push_back(from);
	}

	visited[0] = true;
	dfs(0);

	cout << ans << endl;

	return 0;
}
