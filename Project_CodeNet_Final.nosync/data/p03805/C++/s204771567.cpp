#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
bool f[9];
int n,m,ans=0;
vector<int> mp[9];
void dfs(int step,int p)
{
	if(step==n)
	{
		ans++;
		return;
	}
	int k=mp[p].size();
	for(int i=0;i<k;++i)
	if(f[mp[p][i]])
	{
		f[mp[p][i]]=false;
		dfs(step+1,mp[p][i]);
		f[mp[p][i]]=true;
	}
}
int main()
{
	memset(f,true,sizeof(f));
	scanf("%d%d",&n,&m);
	for(int a,b,i=1;i<=m;++i)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	f[1]=false; dfs(1,1);
	printf("%d",ans);
}