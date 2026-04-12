//abc054_c.cpp
//Tue Jun  5 22:05:14 2018

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;

int graph[8][8] = {};
int visit[8] = {};
int ans = 0;

void dfs(int v, int node, int c) {
	c++;
	visit[v] = 1;
	if (c == node){
		ans++;
	}
	for (int i=0;i<node;i++){
		if (graph[v][i] == 1 && visit[i]==0){
			dfs(i,node,c);
		}
	}
	c--;
	visit[v]--;
}

int main(){
	int n,m;
	cin >> n >> m;

	for (int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	int count = 0;
	dfs(0,n,count);

	cout << ans << endl;
}