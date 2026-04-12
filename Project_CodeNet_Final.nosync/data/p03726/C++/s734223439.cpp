#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
#define MAXN 100000
int n,u,v,F;
vector<int> G[MAXN+5];
int dfs(int x,int fa){
	int p=0;
	for(int i=0;i<G[x].size();i++){
		int nxt=G[x][i];
		if(nxt==fa)continue;
		p+=dfs(nxt,x);
	}
	if(p>=2)F=1;
	return p^1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(dfs(1,0)==0&&!F)printf("Second\n");
	else printf("First");
}