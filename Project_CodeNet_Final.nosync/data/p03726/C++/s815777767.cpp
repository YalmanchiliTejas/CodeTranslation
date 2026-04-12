#include <bits/stdc++.h>

#define For(i, j, k) for(int i = j; i <= k; i++)
#define pb push_back

using namespace std;

const int N = 100010;

vector<int> G[N];
int n;
bool ans;

bool DFS(int o, int f){
	int cnt = 0;
	for(int v : G[o]){
		if(v == f) continue;
		cnt += DFS(v, o);
	}
	if(cnt > 1) ans = true;
	return !cnt;
}

int main(){
	
	while(scanf("%d", &n) == 1){
	
		For(i, 1, n) G[i].clear();
		ans = n & 1;

		For(i, 2, n){
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].pb(v), G[v].pb(u);
		}

		DFS(1, 0);

		puts(ans ? "First" : "Second");
	}

	return 0;
}