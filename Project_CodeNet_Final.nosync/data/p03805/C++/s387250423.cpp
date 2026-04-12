#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

int n,m,cnt,vis[100];
vector <int> e[10];

bool pd()
{
	for (register int i=1;i<=n;i++) if (vis[i]==0) return false;
	return true;
}

void dfs(int x)
{
	vis[x]=1;
	if (pd())
	  {
	  	cnt++;
	  	vis[x]=0;
	  	return;
	  }
	int emm=e[x].size();  
	for (register int i=0;i<emm;i++)
	  {
	  	if (vis[e[x][i]]) continue;
	  	dfs(e[x][i]);
	  }
	vis[x]=0;
	return;  
}

int main()
{
	scanf("%d%d",&n,&m);
	for (register int i=1;i<=m;i++)
	  {
	  	int a,b;
	  	scanf("%d%d",&a,&b);
	  	e[a].push_back(b);
	  	e[b].push_back(a);
	  }
	dfs(1);  
	printf("%d",cnt);
	return 0;
}