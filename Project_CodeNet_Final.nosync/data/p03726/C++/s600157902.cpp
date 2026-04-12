#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define N 1000005
using namespace std;

int n, var[N], coc[N];
vector < int > g[N];
queue < int > q;

void dfs(int node, int par){
	int say = 0;
	for(int i = 0; i < g[node].size(); i++)
		if(g[node][i] != par){
			dfs(g[node][i], node);
			say += var[g[node][i]];
		}
	if(say > 1){
		puts("First");
		exit(0);
	}
	var[node] = !say;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%d",&n);
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d %d",&u ,&v);
		g[u].pb(v);
		g[v].pb(u);
		coc[u]++;
		coc[v]++;
	}
	if(n == 2)
		return puts("Second"), 0;
	for(int i = 1; i <= n; i++)
		if(coc[i] > 1){
			dfs(i, 0);
			if(var[i])
				return puts("First"), 0;
			break;
		}
	puts("Second");
	return 0;
}