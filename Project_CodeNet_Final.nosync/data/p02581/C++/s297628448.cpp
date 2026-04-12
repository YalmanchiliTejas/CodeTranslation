#include<bits/stdc++.h>
using namespace std;

int n,ans,mx;
int a[6005],curdp[2005][2005],dp[2005][2005],f[2005];
int main()
{
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		f[i]=-n*10;
		for(j=i;j<=n;j++)
			dp[i][j]=curdp[i][j]=-n*10;
	}
	for(i=1;i<=n*3;i++)
		scanf("%d",&a[i]);
	dp[min(a[1],a[2])][max(a[1],a[2])]=0;
	f[a[1]]=f[a[2]]=0;
	for(i=5;i<=3*n;i+=3)
	{
		if(a[i]==a[i-1]&&a[i-1]==a[i-2])
		{
			ans++;
			continue;
		}
		int b[3];
		for(k=0;k<3;k++)
			b[k]=a[i-k];
		sort(b,b+3);
		for(k=0;k<3;k++)
		{
			int t=b[k];
			b[k]=-10;
			sort(b,b+3);
			curdp[b[1]][b[2]]=max(curdp[b[1]][b[2]],max(dp[t][t]+1,mx));
			b[0]=t;
			sort(b,b+3);
		}
		for(k=0;k<3;k++)
		{
			int t=b[k];
			b[k]=-10;
			sort(b,b+3);
			if(b[1]==b[2])
			{
				for(j=1;j<=n;j++)
					curdp[min(t,j)][max(t,j)]=max(curdp[min(t,j)][max(t,j)],dp[min(b[1],j)][max(b[1],j)]+1);
			}
			for(j=1;j<=n;j++)
				curdp[min(t,j)][max(t,j)]=max(curdp[min(t,j)][max(t,j)],f[j]);
			b[0]=t;
			sort(b,b+3);
		}
		for(k=0;k<3;k++)
		{
			int t=b[k];
			b[k]=-10;
			sort(b,b+3);
			dp[b[1]][b[2]]=max(dp[b[1]][b[2]],curdp[b[1]][b[2]]);
			mx=max(mx,dp[b[1]][b[2]]);
			f[b[1]]=max(f[b[1]],dp[b[1]][b[2]]);
			f[b[2]]=max(f[b[2]],dp[b[1]][b[2]]);
			//curdp[b[1]][b[2]]=-n*10;
			for(j=1;j<=n;j++)
			{
				dp[min(t,j)][max(t,j)]=max(curdp[min(t,j)][max(t,j)],dp[min(t,j)][max(t,j)]);
				mx=max(mx,dp[min(t,j)][max(t,j)]);
				f[t]=max(f[t],dp[min(t,j)][max(t,j)]);
				f[j]=max(f[j],dp[min(t,j)][max(t,j)]);
				//curdp[min(t,j)][max(t,j)]=-n*10;
			}
			b[0]=t;
			sort(b,b+3);
		}
	}
	printf("%d\n",ans+max(mx,dp[a[n*3]][a[n*3]]+1));
	return 0;
}
