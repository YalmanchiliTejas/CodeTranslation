#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

const int Maxn = 100010;

vector<int> edge[Maxn];

int n, siz[100010];

void dfs(int u, int fa) {
	siz[u] = 1;
	int cnt = 0;
	for(int it = 0; it < edge[u].size(); ++it) 
		if(edge[u][it] != fa) {
			dfs(edge[u][it], u);
			siz[u] += siz[edge[u][it]];
			if(siz[edge[u][it]]&1) cnt++;
		}
	if((n-siz[u])&1) cnt++;
	if(cnt >= 2) {
		puts("First");
		exit(0);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edge[u].pb(v);
		edge[v].pb(u);
	}
	dfs(1, 0);
	puts("Second");
	return 0;
}