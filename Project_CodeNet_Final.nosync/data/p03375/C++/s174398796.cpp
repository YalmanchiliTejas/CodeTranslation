#include<stdio.h>
int s[3005][3005],c[3005][3005];
int main()
{
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=0;i<=n;i++)
	{
		s[i][0]=1;
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			s[i][j]=s[i-1][j-1]+(long long)s[i-1][j]*(j+1)%p;
			if(s[i][j]>=p)
			{
				s[i][j]-=p;
			}
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			if(c[i][j]>=p)
			{
				c[i][j]-=p;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int mt1=1,mt2=2;
		for(int j=0;j<n-i;j++)
		{
			mt1<<=1;
			if(mt1>=p)
			{
				mt1-=p;
			}
			mt2=(long long)mt2*mt2%p;
		}
		int val=0;
		for(int j=i;j>=0;j--)
		{
			val=(long long)val*mt1%p;
			val+=s[i][j];
			if(val>=p)
			{
				val-=p;
			}
		}
		val=(long long)val*mt2%p;
		if(i&1)
		{
			ans-=(long long)val*c[n][i]%p;
			if(ans<0)
			{
				ans+=p;
			}
		}
		else
		{
			ans+=(long long)val*c[n][i]%p;
			if(ans>=p)
			{
				ans-=p;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}