#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100000;
vector<int> d[MAXN+5];
int n;
int dfs(int u,int fa)
{
	int res=0,v;
	for(int i=0;i<d[u].size();i++)
	{
		v=d[u][i];
		if(v!=fa)
			res+=dfs(v,u);
	}
	if(res>=2)
	{
		printf("First");
		exit(0);
	}
	else if(res==0)
		return 1;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		d[u].push_back(v);
		d[v].push_back(u);
	}
	if(dfs(1,0))
		printf("First");
	else
		printf("Second");
	return 0;
}
