#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int MaxN = 100 + 5;
int n, m;
int pre[2 * MaxN], last[MaxN], other[2 * MaxN];
int all = -1;
bool vis[MaxN];
int ans;
void Build(int u, int v){
	pre[++all] = last[u];
	last[u] = all;
	other[all] = v;
}
void Dfs(int x, int cont){
	if(vis[x]) return;
	vis[x] = true;
	cont++;
	int ed, dr;
	ed = last[x];
	while(ed != -1){
		dr = other[ed];
		Dfs(dr, cont);
		ed = pre[ed];
	}
	if(cont == n) ans++;
	cont--;
	vis[x] = false;
}
	
int main(){
	while(~scanf("%d %d", &n, &m)){
		memset(pre, 0, sizeof(pre));
		memset(last, - 1, sizeof(last));
		memset(other, 0, sizeof(other));
		all = -1;
		ans = 0;
		int u, v;
		for(int i = 1; i <= m; i++){
			scanf("%d %d", &u, &v);
			Build(u, v);
			Build(v, u);
		}
		Dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}
