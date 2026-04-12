#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#define maxn 2005
#define mid ((nl+nr)>>1)
using namespace std;
typedef long long ll;
int n;
int a[maxn*3];
int dp[maxn][maxn];
int maxx[maxn];
int x[maxn*100],y[maxn*100],z[maxn*100];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=3*n;i++)
		scanf("%d",&a[i]);
		
	memset(dp,-1,sizeof(dp));
	memset(maxx,-1,sizeof(maxx));
	
	int nowmax=0,gg=0;
	dp[a[1]][a[2]]=0;
	dp[a[2]][a[1]]=0;
	maxx[a[1]]=0;
	maxx[a[2]]=0;
	
	for(int i=3;i<3*n;i+=3)
	{
		if(a[i]==a[i+1] && a[i+1]==a[i+2])
		{
			gg++;
			continue;
		}
		sort(a+i,a+i+3);
		int tot=0;
		if(a[i]==a[i+1])
		{
			for(int j=1;j<=n;j++)
			if(dp[j][a[i]]!=-1)
			{
				tot++;
				x[tot]=j;
				y[tot]=a[i+2];
				z[tot]=dp[j][a[i]]+1;
			}
		}
		if(a[i+1]==a[i+2])
		{
			for(int j=1;j<=n;j++)
			if(dp[j][a[i+1]]!=-1)
			{
				tot++;
				x[tot]=j;
				y[tot]=a[i];
				z[tot]=dp[j][a[i+1]]+1;
			}
		}
		if(dp[a[i]][a[i]]!=-1)
		{
			tot++;
			x[tot]=a[i+1];
			y[tot]=a[i+2];
			z[tot]=dp[a[i]][a[i]]+1;
		}
		if(dp[a[i+1]][a[i+1]]!=-1)
		{
			tot++;
			x[tot]=a[i];
			y[tot]=a[i+2];
			z[tot]=dp[a[i+1]][a[i+1]]+1;
		}
		if(dp[a[i+2]][a[i+2]]!=-1)
		{
			tot++;
			x[tot]=a[i+1];
			y[tot]=a[i];
			z[tot]=dp[a[i+2]][a[i+2]]+1;
		}
		
		tot++;
		x[tot]=a[i+1];
		y[tot]=a[i];
		z[tot]=nowmax;
		
		tot++;
		x[tot]=a[i+1];
		y[tot]=a[i+2];
		z[tot]=nowmax;
		
		tot++;
		x[tot]=a[i];
		y[tot]=a[i+2];
		z[tot]=nowmax;
		
		for(int j=0;j<3;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(maxx[k]!=-1)
				{
					tot++;
					x[tot]=a[i+j];
					y[tot]=k;
					z[tot]=maxx[k];
				}
			}
		}
		
		for(int j=1;j<=tot;j++)
		{
			dp[x[j]][y[j]]=dp[y[j]][x[j]]=max(dp[x[j]][y[j]],z[j]);
			maxx[x[j]]=max(maxx[x[j]],z[j]);
			maxx[y[j]]=max(maxx[y[j]],z[j]);
			nowmax=max(nowmax,dp[x[j]][y[j]]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans=max(ans,dp[i][j]);
		}
	}
	ans=max(ans,dp[a[3*n]][a[3*n]]+1);
	printf("%d\n",ans+gg);
}