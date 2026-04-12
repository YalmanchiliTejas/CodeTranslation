#include <bits/stdc++.h>
using namespace std;

const int nmax=8;
bool graph[nmax][nmax];

int dfs(int v,int n,bool visited[nmax]){
	bool all=true;
	for(int i=0;i<n;i++){
		if(visited[i]==false) all=false;
	}
	if(all) return 1;
	int ret=0;
	for(int i=0;i<n;i++){
		if(graph[v][i]==false) continue;
		if(visited[i]) continue;
		visited[i]=true;
		ret+=dfs(i,n,visited);
		visited[i]=false;
	}
	return ret;
}

int main() {
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		graph[a-1][b-1]=true;
		graph[b-1][a-1]=true;
	}
	bool visited[nmax];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	visited[0]=true;
	cout << dfs(0,n,visited) << endl;
	return 0;
}
