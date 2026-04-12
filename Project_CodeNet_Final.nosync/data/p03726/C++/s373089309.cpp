#include <bits/stdc++.h>

#define For(i, j, k) for(int i = j; i <= k; i++)
#define pb push_back

using namespace std;

const int N = 100010;

vector<int> G[N];
int n;
int leaf[N][2];
bool ans;

void DFS(int o, int f){
	if(G[o].size() == 1){
		leaf[o][1] = true;
		return;
	}
	for(int v : G[o]){
		if(v == f) continue;
		DFS(v, o);
		For(i, 0, 1) leaf[o][i] += leaf[v][i ^ 1];
	}
	if(leaf[o][0] > 1) ans = true;
	if(leaf[o][1] > 1 && !f && G[o].size() == 2) ans = true;
	For(i, 0, 1) leaf[o][i] = bool(leaf[o][i]);
	if(G[o].size() > 2 && leaf[o][0]) leaf[o][1] = false;
}

int main(){
	scanf("%d", &n);

	if(n == 2){
		puts("Second");
		return 0;
	}

	For(i, 2, n){
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].pb(v), G[v].pb(u);
	}

	int rt = 0;
	For(i, 1, n) if(G[i].size() != 1) rt = i;
	DFS(rt, 0);

	puts(ans ? "First" : "Second");
	return 0;
}