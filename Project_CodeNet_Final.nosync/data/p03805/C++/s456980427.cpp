#include"bits/stdc++.h"
using namespace std;
#define LL long long

LL N,M,K,ans,r;
LL a, b;
string s;
bool graph[9][9];
int dfs(LL now,bool visit[],LL V) {
	for (int i = 1; i < V + 1; i++) {
		if (visit[i] == false) {
			break;
		}
		else if(i==V){
			return 1;
		}
	}
	int num = 0;

	for (int i = 1; i <= V; i++) {
		if (visit[i] == false && graph[now][i] == true) {
			visit[i] = true;
			num += dfs(i, visit, V);
			visit[i] = false;
		}
	}
	return num;
}
int main() {

	cin >> N>>M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			graph[i][j] = false;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	bool v[9];
	for (int i = 1; i <= N; i++) {
		v[i] = false;
	}
	v[1] = true;
	cout << dfs(1,v,N) << endl;
	return 0;

}
