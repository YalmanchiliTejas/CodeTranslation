#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int size = 1005;
vector<int> gra[size];
int vis[size];

int n, m;
int ans = 0;

void dfs(int a, int num) {
	if(num == n) {
		ans ++;
		return ;
	}

	for ( int i = 0; i < gra[a].size(); i ++ ) {
		if(!vis[gra[a][i]]) {
			vis[gra[a][i]] = 1;
			dfs(gra[a][i], num+1);
			vis[gra[a][i]] = 0;
		}
	}
}

int main() {	
	scanf("%d %d", &n, &m);
	for ( int i = 1; i <= m; i ++ ) {
		int u, v;
		scanf("%d %d", &u, &v);
		gra[u].push_back(v); gra[v].push_back(u);
	}

	vis[1] = 1;
	dfs(1, 1);
	printf("%d\n", ans);

	return 0;
}