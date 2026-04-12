#include<stdio.h>
int a[16384];
int md[8192];
void fft()
{
	int k=0;
	for(int i=1;i<16384;i<<=1)
	{
		for(int j=0;j<16384;j++)
		{
			if(j&i)
			{
				int t=(long long)a[j]*md[(j&(i-1))<<(13-k)]%998244353;
				a[j]=(a[j-i]-t+998244353)%998244353;
				a[j-i]=(a[j-i]+t)%998244353;
			}
		}
		k++;
	}
}
int tmp[16384];
int rv[16384];
int jc[16384],injc[16384];
int dp[16384];
int main()
{
	md[0]=1;
	for(int i=1;i<8192;i++)
	{
		md[i]=(long long)md[i-1]*666702199%998244353;
	}
	rv[0]=0;
	for(int i=1;i<16384;i++)
	{
		rv[i]=rv[i>>1]>>1;
		if(i&1)
		{
			rv[i]+=8192;
		}
	}
	int n,m;
	scanf("%d%d",&n,&m);
	injc[1]=1;
	for(int i=2;i<=n+2;i++)
	{
		injc[i]=(long long)998244353/i*injc[998244353%i]%998244353;
		injc[i]=998244353-injc[i];
	}
	jc[0]=1;
	injc[0]=1;
	for(int i=1;i<=n+2;i++)
	{
		jc[i]=(long long)jc[i-1]*i%998244353;
		injc[i]=(long long)injc[i-1]*injc[i]%998244353;
	}
	dp[0]=1;
	while(m--)
	{
		for(int i=0;i<16384;i++)
		{
			if(rv[i]>n)
			{
				a[i]=0;
			}
			else
			{
				a[i]=(long long)dp[rv[i]]*injc[rv[i]]%998244353;
			}
		}
		fft();
		for(int i=0;i<16384;i++)
		{
			tmp[i]=a[i];
			if(rv[i]>n||rv[i]==0)
			{
				a[i]=0;
			}
			else
			{
				a[i]=injc[rv[i]+2];
			}
		}
		fft();
		for(int i=0;i<16384;i++)
		{
			tmp[i]=(long long)tmp[i]*a[i]%998244353;
		}
		for(int i=0;i<16384;i++)
		{
			a[i]=tmp[rv[i]];
		}
		fft();
		for(int i=0;i<=n;i++)
		{
			dp[i]=(long long)dp[i]*(i*(i+1)/2+1)%998244353;
			int inc=(long long)a[(16384-i)&16383]*998183425%998244353;
			dp[i]+=(long long)inc*jc[i+2]%998244353;
			if(dp[i]>=998244353)
			{
				dp[i]-=998244353;
			}
		}
	}
	int answer=0;
	for(int i=0;i<=n;i++)
	{
		int inc=(long long)dp[i]*jc[n]%998244353;
		inc=(long long)inc*injc[i]%998244353;
		inc=(long long)inc*injc[n-i]%998244353;
		answer+=inc;
		if(answer>=998244353)
		{
			answer-=998244353;
		}
	}
	printf("%d\n",answer);
	return 0;
}