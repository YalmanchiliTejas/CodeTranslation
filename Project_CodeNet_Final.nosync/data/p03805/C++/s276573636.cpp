#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
vector<int>link[100];
bool vis[100];
int num=0;
int tot=1;
int n,m;
void dfs(int v)
{
	if(tot==n)
	{
		num++;
		return;
	}
	int ss=link[v].size();
	for(int i=0;i<ss;i++)
	{
		if(vis[link[v][i]]==false)
		{
			tot++;
			vis[link[v][i]]=true;
			dfs(link[v][i]);
			tot--;
			vis[link[v][i]]=false;
		}
	}
}
int main()
{
	memset(vis,false,sizeof(vis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		link[a].push_back(b);
		link[b].push_back(a);
	}
	vis[1]=true;
	dfs(1);
	printf("%d",num);
	return 0;
} 