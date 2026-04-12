#include<cstdio>
#include<vector>
using namespace std;
const int maxn=100000;
int n,f[maxn+10][2];
vector<int> g[maxn+10];
void dfs(int x,int fa){
	int now=1e9;
	for(int i=0;i<g[x].size();++i){
		int e=g[x][i]; if(e==fa) continue;
		dfs(e,x); f[x][0]+=f[e][1]; now=min(now,f[e][1]-f[e][0]);
	}
	f[x][1]=max(f[x][0],f[x][0]-now+1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int l,r; scanf("%d%d",&l,&r);
		g[l].push_back(r); g[r].push_back(l);
	}
	dfs(1,0); if(f[1][1]*2==n) printf("Second"); else printf("First");
}