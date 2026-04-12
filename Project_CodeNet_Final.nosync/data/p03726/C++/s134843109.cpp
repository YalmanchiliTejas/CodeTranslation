#include <bits/stdc++.h>
#define N 1000500
using namespace std;
inline int rd() {int r;scanf("%d",&r);return r;}
vector<int> e[N];
int p[N],n;
void link(int a,int b) {e[a].push_back(b), e[b].push_back(a);}

void dfs(int u,int f) {
	for (int i=0;i<(int)e[u].size();i++) {
		int v=e[u][i]; if (v==f) continue;
		dfs(v,u);
	}
	if (!p[u] && !p[f]) p[u] = p[f] = 1; 
}

int main() {
	n = rd();
	for (int i=1;i<n;i++) link(rd(),rd());
	p[0] = 1;
	dfs(1,0);
	int ans = 1;
	for (int i=1;i<=n;i++) if (!p[i]) ans = 0;
	puts(!ans?"First":"Second");
	return 0;
}