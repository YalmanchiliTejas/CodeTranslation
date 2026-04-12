#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
const int MaxN = 2e5;
using namespace std;
int pre[2 * MaxN + 5] , last[MaxN + 5] , other[2 * MaxN + 5];
int n;
int all = -1 , ok = 0;
void Build(int u , int v){
	pre[++all] = last[u];
	last[u] = all;
	other[all] = v;
}
void Init(){
	memset(last , -1 , sizeof(last));
	all = -1 , ok = 0;
	for(int i = 1;i <= n - 1;i++){
		int u , v;
		scanf("%d%d" , &u , &v);
		Build(u , v); Build(v , u);
	}
}
int dfs(int x , int fa){
	int ed = last[x];
	int cont = 0 ;
	while(ed != -1){
		int dr = other[ed];
		if(dr != fa) {
			if(dfs(dr , x)) cont++;
		}
		ed = pre[ed];
	}
	if(cont >= 2){
		ok = 1;
	}
	return !cont;
}
void Solve(){
	if(dfs(1 , 0) == 1 || ok) printf("First\n");
	else printf("Second\n");
}
int main()
{
	while(~scanf("%d" , &n)){
		Init();
		Solve();
	}
}