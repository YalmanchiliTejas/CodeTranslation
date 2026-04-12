#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define print(x) cout<<x<<endl;
typedef long long ll;


bool graph[8][8];

int dfs(int v,int N,bool visited[8]){
	bool all_visited = true;

	rep(i, 0, N) {
		if (visited[i] == false)
			all_visited = false;
	}
	if (all_visited) return 1;

	int ret = 0;
	rep(i, 0, N) {
		if (graph[v][i] == false)continue;
		if (visited[i]) continue;

		visited[i] = true;
		ret += dfs(i, N, visited);
		visited[i] = false;
	}

	return ret;
}

int main() {
	int N, M;
	int A, B;
	cin >> N >> M;
	rep(i, 0, M) {
		cin >> A >> B;
		graph[A - 1][B - 1] = graph[B - 1][A - 1] = true;
	}

	bool visited[8];
	rep(i, 0, N) {
		visited[i] = false;
	}
	visited[0] = true;
	print(dfs(0, N, visited));
	return 0;
}
