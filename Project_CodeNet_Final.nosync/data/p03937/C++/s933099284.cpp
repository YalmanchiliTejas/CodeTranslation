#include <bits/stdc++.h>
using namespace std;
const int maxn = 11;
char g[maxn][maxn];
int cnt = 0, n, m;
void dfs(int i, int j){
	cnt++;
	if(i == n && j == m) return;
	if(g[i + 1][j] == '#'){
		dfs(i + 1, j);
		return;
	}
	if(g[i][j + 1] == '#'){
		dfs(i, j + 1);
		return;
	}
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> g[i + 1][j + 1];
	int need = 0;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) if(g[i][j] == '#') need++;
	if(g[1][1] == '#')dfs(1, 1);
	if(need == cnt) printf("Possible\n");
	else printf("Impossible\n");
	return 0;
}
