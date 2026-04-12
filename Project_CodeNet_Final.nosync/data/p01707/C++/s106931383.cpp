#include<iostream>
using namespace std;
int N,X;
long D;
long mod=1e9+7;
long dp[2002],ED[2001];
long power(long a,long b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
long C(long a,long b)
{
	long s=1,t=1;
	for(long i=1;i<=b;i++)
	{
		s=s*((a-i+1)%mod)%mod;
		t=t*i%mod;
	}
	return s*power(t,mod-2)%mod;
}
main()
{
	while(cin>>N>>D>>X,N)
	{
		for(int i=0;i<=N;i++)dp[i]=0;
		for(int i=0;i<=N;i++)ED[i]=0;
		dp[0]=1;
		for(int k=0;k<=N;k++)
		{
			ED[k]=dp[N];
			dp[N]=0;
			for(int j=N;j--;)
			{
				dp[j+1]+=dp[j];
				if(j+X<=N)dp[j+X]-=dp[j];
				dp[j]=0;
			}
			for(int j=0;j<=N;j++)
			{
				dp[j]=(dp[j]%mod+mod)%mod;
				dp[j+1]+=dp[j];
			}
		}
		long ans=0;
		for(int k=0;k<=N&&k<=D;k++)
		{
			(ans+=ED[k]*C(D,k)%mod)%=mod;
		}
		cout<<ans<<endl;
	}
}

