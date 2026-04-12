#include<bits/stdc++.h>
#define pb push_back

using namespace std;

const int N=100005;
vector<int>e[N];int n;
bool dfs(int x,int fa){int m=0;for(int v:e[x])if(v!=fa)m+=dfs(v,x); if(m>1)puts("First"),exit(0);return m^1;}

int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),e[u].pb(v),e[v].pb(u);
	if(dfs(1,0))puts("First");else puts("Second");
	return 0;
}