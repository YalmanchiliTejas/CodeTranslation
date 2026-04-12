#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> point[100001];
int n,x,y,siz[100001],son[100001];
bool check[100001];

void dfs1(int u,int f){siz[u]=1;for(int v:point[u])if(v!=f)dfs1(v,u),siz[u]+=siz[v];}

void dfs2(int u,int f){
	for(int v:point[u])if(v!=f){dfs2(v,u);if(siz[v]>0)++son[u];}
	if(son[u]==1)siz[u]=0;if(son[u]>1)puts("First"),exit(0);
}

int main(){
	scanf("%d",&n);for(int i=1;i<n;++i)scanf("%d%d",&x,&y),point[x].push_back(y),point[y].push_back(x);
	dfs1(1,0);dfs2(1,0);
	puts(siz[1]?"First":"Second");
}