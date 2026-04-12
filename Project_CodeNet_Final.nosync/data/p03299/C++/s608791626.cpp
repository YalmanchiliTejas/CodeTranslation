#include<stdio.h>
int mt(int a,int b)
{
	if(b==0)
	{
		return 1;
	}
	int c=mt(a,b>>1);
	c=(long long)c*c%1000000007;
	if(b&1)
	{
		c=(long long)c*a%1000000007;
	}
	return c;
}
int h[128];
void sol(int l,int r,int& dp1,int& dp2)
{
	int mn=1000000007;
	for(int i=l;i<=r;i++)
	{
		if(h[i]<mn)
		{
			mn=h[i];
		}
	}
	for(int i=l;i<=r;i++)
	{
		h[i]-=mn;
	}
	dp1=2;
	dp2=1;
	int pre=0;
	for(int i=l;i<=r;i++)
	{
		if(h[i])
		{
			if(!pre)
			{
				pre=i;
			}
		}
		else
		{
			if(pre)
			{
				int tmp1,tmp2;
				sol(pre,i-1,tmp1,tmp2);
				dp1=(long long)dp1*tmp1%1000000007;
				dp2=(long long)dp2*(tmp1+tmp2)%1000000007;
				pre=0;
			}
			dp2<<=1;
			if(dp2>=1000000007)
			{
				dp2-=1000000007;
			}
		}
	}
	if(pre)
	{
		int tmp1,tmp2;
		sol(pre,r,tmp1,tmp2);
		dp1=(long long)dp1*tmp1%1000000007;
		dp2=(long long)dp2*(tmp1+tmp2)%1000000007;
		pre=0;
	}
	dp2-=dp1;
	if(dp2<0)
	{
		dp2+=1000000007;
	}
	dp1=(long long)dp1*mt(2,mn-1)%1000000007;
	dp2+=dp1;
	if(dp2>=1000000007)
	{
		dp2-=1000000007;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
	}
	int dp1,dp2;
	sol(1,n,dp1,dp2);
	printf("%d\n",dp2);
	return 0;
}