#include<cstdio>
#include<vector>
using namespace std;
const int INF=1e9+7;
const int N=100005;
int n;
vector<int>G[N];
int Dfs(int u,int fa) {
	int ret=1;
	for(int i=0;i<G[u].size();i++) {
		int v=G[u][i];
		if(v==fa) continue;
		ret+=Dfs(v,u);
	}
	if(ret<1||ret>=3) return -INF;
	return ret%2;
}
int main() {
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++) {
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(Dfs(1,1)!=0)
		printf("First\n");
	else printf("Second\n");
	return 0; 
}