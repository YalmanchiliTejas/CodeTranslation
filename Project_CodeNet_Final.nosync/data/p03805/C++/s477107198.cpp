#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<float.h>

#define MAX_NUM 29

void dfs(int i, bool adj[MAX_NUM][MAX_NUM], bool *visited, int n, int *ans){
	bool allVisited = true;
	for(int j=1; j<n+1; j++){
		if(!visited[j]) allVisited = false;
	}
	if(allVisited) {
		(*ans)++;
		return;
	}
	for(int j=1; j<n+1; j++){
		if((adj[i][j] || adj[j][i]) && !visited[j]) {
			visited[j] = true;
			dfs(j, adj, visited, n, ans);
			visited[j] = false;
		}
	}
}

void count(bool adj[MAX_NUM][MAX_NUM], int n, int *ans){
	bool visited[MAX_NUM];
	visited[1] = true;
	for(int i=2; i<n+1; i++){
		visited[i] = false;
	}
	dfs(1, adj, visited, n, ans);
}

int main(){
	int n, m, a, b, ans = 0;
	bool adj[MAX_NUM][MAX_NUM];
	scanf("%d%d\n", &n, &m);
	for(int i=1; i<n+1; i++){
		for(int j=1; j<n+1; j++){
			adj[i][j] = false;
		}
	}
	for(int i=0; i<m; i++){
		scanf("%d%d\n", &a, &b);
		adj[a][b] = true;
	}
	count(adj, n, &ans);
	printf("%d\n", ans);
	return 0;
}


