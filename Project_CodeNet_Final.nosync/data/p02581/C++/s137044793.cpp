#include<bits/stdc++.h>
using namespace std;
const int N=6005;
int n,dp[N][N],a[N],mx[N],m,ans,zh;
void upd(int x,int y,int v)
{
	dp[x][y]=max(dp[x][y],v);
	dp[y][x]=max(dp[y][x],v);
	mx[x]=max(mx[x],v);
	mx[y]=max(mx[y],v);
	m=max(m,v);
}
vector<tuple<int,int,int>>q;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*3;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		mx[i]=-1e9;
		for(int j=1;j<=n;j++)
			dp[i][j]=-1e9;
	}	
	upd(a[1],a[2],0);
	for(int i=3;i+3<=n*3;i+=3)
	{
		sort(a+i,a+i+3);
		q.clear();
		if(a[i]==a[i+2])
		{
			zh++;
			continue;
		}
		if(a[i]==a[i+1])
			for(int j=1;j<=n;j++)
				q.emplace_back(j,a[i+2],dp[a[i]][j]+1);
		if(a[i+1]==a[i+2])
			for(int j=1;j<=n;j++)
				q.emplace_back(j,a[i],dp[a[i+1]][j]+1);
		for(int j=i;j<i+3;j++)
		{
			q.emplace_back(j==i?a[i+1]:a[i],j==i+2?a[i+1]:a[i+2],dp[a[j]][a[j]]+1);
			q.emplace_back(j==i?a[i+1]:a[i],j==i+2?a[i+1]:a[i+2],m);
		}
		for(int j=1;j<=n;j++)
			for(int k=i;k<i+3;k++)
				q.emplace_back(j,a[k],mx[j]);
		for(auto &j:q)
		{
			int x,y,v;
			tie(x,y,v)=j;
			upd(x,y,v);
		}
	}
	dp[a[n*3]][a[n*3]]++;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans=max(ans,dp[i][j]);
	printf("%d\n",ans+zh);
	return 0;
}