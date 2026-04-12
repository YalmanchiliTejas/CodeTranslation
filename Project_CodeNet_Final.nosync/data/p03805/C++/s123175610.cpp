#include<stdio.h>
#include<vector>
using namespace std;
vector<int>a[100];
int n,m,ans,b[100];
int vis[100];
void dfs(int u,int d) {
	b[d]=u;
	vis[u]=1;
	if(d==n) {
		ans++;
	}
	for(int i=0; i<a[u].size(); i++) {
		if(vis[a[u][i]]==0) {
			dfs(a[u][i],d+1);
			vis[a[u][i]]=0;
		}
	}
}
int main() {
	int i,v1,v2;
	scanf("%d%d",&n,&m);
	for(i=0; i<m; i++) {
		scanf("%d%d",&v1,&v2);
		a[v1].push_back(v2);
		a[v2].push_back(v1);
	}
	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}