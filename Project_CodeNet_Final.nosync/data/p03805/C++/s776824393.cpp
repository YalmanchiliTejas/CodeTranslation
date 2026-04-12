#include<cstdio>
#include<vector>
using namespace std;
vector<int> x[100];
int n,m,boolx,ans;
bool vis[100];
void init(){
	scanf("%d%d",&n,&m);
	for(int a,b,i=1;i<=m;++i){
		scanf("%d%d",&a,&b);
		x[b].push_back(a);
		x[a].push_back(b);
	}
}
void dfs(int v){
	vis[v]=true; boolx++;
	if(boolx==n) {
		ans++;  return;
	}
	for(int i=x[v].size()-1;i>=0;--i){
		if(!vis[x[v][i]]){
			dfs(x[v][i]);
			vis[x[v][i]]=false;
			boolx--;
		}
	}
}
int main(){
	init();
	dfs(1);        
	printf("%d",ans);
	return 0;
}
/*
3 3
1 2
1 3
2 3
*/
/*
7 7
1 3
2 7
3 4
4 5
4 6
5 6
6 7
*/