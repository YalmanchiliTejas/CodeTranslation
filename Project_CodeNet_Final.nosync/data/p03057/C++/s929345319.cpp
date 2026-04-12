#include<stdio.h>
char s[262144];
int dp[262144];
int pre[262144];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	bool fir=true;
	int num=0;
	int mx=n;
	for(int i=0;i<m;i++)
	{
		if(s[i]==s[0])
		{
			num++;
		}
		else
		{
			if(fir||(num&1))
			{
				if(num<mx)
				{
					mx=num;
				}
			}
			fir=false;
			num=0;
		}
	}
	if(fir)
	{
		for(int i=2;i<=n;i++)
		{
			dp[i]=i;
			dp[i]+=pre[i-2];
			if(dp[i]>=1000000007)
			{
				dp[i]-=1000000007;
			}
			pre[i]=pre[i-1]+dp[i];
			if(pre[i]>=1000000007)
			{
				pre[i]-=1000000007;
			}
		}
		int ans=dp[n]+1;
		if(ans>=1000000007)
		{
			ans-=1000000007;
		}
		printf("%d\n",ans);
		return 0;
	}
	if(n&1)
	{
		printf("0\n");
		return 0;
	}
	if(!(mx&1))
	{
		mx++;
	}
	mx++;
	n>>=1;
	mx>>=1;
	for(int i=1;i<=n;i++)
	{
		dp[i]=pre[i-1];
		if(i<=mx)
		{
			dp[i]+=(i<<1);
			if(dp[i]>=1000000007)
			{
				dp[i]-=1000000007;
			}
		}
		else
		{
			dp[i]-=pre[i-mx-1];
			if(dp[i]<0)
			{
				dp[i]+=1000000007;
			}
		}
		pre[i]=pre[i-1]+dp[i];
		if(pre[i]>=1000000007)
		{
			pre[i]-=1000000007;
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}