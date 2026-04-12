#include<bits/stdc++.h>
using namespace std;

#define MAX_N 8
int graph[MAX_N][MAX_N];


int dfs(int idx,int n,bool visited[MAX_N]){
	

	bool all_visited=true;
	for(int i=0;i<n;i++){
		if(!visited[i]) all_visited=false;
	}
	if(all_visited){
		return 1;
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(!graph[idx][i])continue;
		if(visited[i])continue;
		visited[i] = true;
		int a = dfs(i,n,visited);
		cnt += a;
		visited[i]=false;
	}
	return cnt;
}


int main() {
    int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) graph[i][j]=false;
	}
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >>b;
		a--;b--;
		graph[a][b]=true;
		graph[b][a]=true;
	}
	bool visited[MAX_N];
	for(int i=1;i<n;i++){
		visited[i]=false;
	}
	visited[0]=true;
	int ret = dfs(0,n,visited);
	
	cout << ret << endl;
    return 0;
}

