#include<iostream>
using namespace std;
long a,b,c,d;
long M=1e9+7;
long p(long a,int b)
{
	long ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=M;
		a*=a;
		a%=M;
		b>>=1;
	}
	return ans;
}
long P(int n,int m)
{
	long ans=1LL;
	for(int i=m-1;i>=0;i--)ans*=n-i,ans%=M;
	return ans;
}
long dp[1001][1001];
long e[1001];
long PC[1001][1001];
long PW[1001][1001];
main()
{
	long n;
	cin>>n>>a>>b>>c>>d;
	for(int i=0;i<=n;i++)dp[i][0]=1;
	e[0]=1;
	for(int i=1;i<=n;i++)e[i]=e[i-1]*i%M;
	for(int i=0;i<=n;i++)
	{
		for(int j=i;j>=0;j--)
		{
			PC[i][j]=e[i]*p(e[i-j],M-2)%M;
		}
	}
	for(int i=0;i<=n;i++)e[i]=p(e[i],M-2);
	for(int i=a;i<=b;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=dp[i-1][j];
			for(int k=c;k<=d&&j-i*k>=0;k++)
			{
				(dp[i][j]+=dp[i-1][j-i*k]*PC[n-j+i*k][i*k]%M*p(e[i],k)%M*e[k]%M)%=M;
			}
		}
	}
	cout<<dp[b][n]<<endl;
}