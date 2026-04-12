#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
int n,m,e[30][30],a,b,ans;
void dfs(int r,int c,int v)
{
	v+=1<<r;
	if(c==n)
	{
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(e[r][i]&&!(1<<i&v))dfs(i,c+1,v);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		e[a][b]=1;
		e[b][a]=1;
	}
	dfs(1,1,0);
	cout<<ans<<endl;
}