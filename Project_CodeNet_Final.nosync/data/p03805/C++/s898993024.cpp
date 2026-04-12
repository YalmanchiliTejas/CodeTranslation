#include <bits/stdc++.h>
using namespace std;

int N, M, T;
vector<int> A[9];

void dfs(int node, vector<bool> vis, int sum){
	if(sum == N) T++;
	else{
		vis[node] = true, sum++;
		for(int i = 0; i < A[node].size(); i++)
			if(!vis[A[node][i]]) dfs(A[node][i], vis, sum);
	}
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		A[a].push_back(b), A[b].push_back(a);
	}
	dfs(1, {false, false, false, false, false, false, false, false, false}, 1);
	printf("%d\n", T);
	return 0;
}
