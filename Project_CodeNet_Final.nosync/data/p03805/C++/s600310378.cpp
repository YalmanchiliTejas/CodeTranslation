#include<bits/stdc++.h>
using namespace std;
static const int MAX_N = 8;

int N, M;
int D[8][8];
int V[8];
int ans;

void dfs(int num){
	bool def = true;
	for(int i = 0; i < N; i++){
		if(V[i] == 0) def = false;
	}
	if(def == true) ans++;
	for(int i = 0; i < N; i++){
		if(D[num][i] == 1 && V[i] == 0){
			V[i] = 1;
			dfs(i);
			V[i] = 0;
		}
	}
}

void solve(){
	ans = 0;
	V[0] = 1;
	dfs(0);
	printf("%d\n", ans);
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			D[i][j] = 0;
		}
	}
	int a, b;
	for(int i = 0; i < M; i++){
		scanf("%d %d", &a, &b);
		a--; b--;
		D[a][b] = 1;
		D[b][a] = 1;
	}
	solve();
	return 0;
}
