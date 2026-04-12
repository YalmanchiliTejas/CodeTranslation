#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int head[100];
int cnt;
int vist[10];
vector<int>vec[10];
int n,m;
void dfs(int x,int sum)
{
	if(sum==n)
	{
		cnt++;
		return;
	}
	vist[x]=1;
	for(int i=0;i<vec[x].size();i++)
	{
		if(!vist[vec[x].at(i)])
		{
			vist[vec[x].at(i)]=1;
			dfs(vec[x].at(i),sum+1);
			vist[vec[x].at(i)]=0;
		}
	}
}
int main(){
	while(scanf("%d %d",&n,&m)==2)
	{
		cnt=0;
		memset(vist,0,sizeof(vist));
		for(int i=1;i<=n;i++)
		vec[i].clear();
		for(int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		dfs(1,1);
		printf("%d\n",cnt);
	}
	return 0;
} 