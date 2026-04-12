#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007

ll dp[10001][2][101];

ll solve(string &k,ll d,ll i,ll tight,ll sum)
{
	sum=sum%d;
	if(i==k.length())
	{
		if(sum%d==0)
		{
			return(1);
		}
		else
		{
			return(0);
		}
	}
	if(dp[i][tight][sum]!=-1)
	{
		return(dp[i][tight][sum]);
	}
	if(tight==0)
	{
		ll ans=0,j;
		for(j=0;j<=9;j++)
		{
			ans=(ans%mod+solve(k,d,i+1,0,sum+j)%mod)%mod;;
		}
		return(dp[i][tight][sum]=ans%mod);
	}
	else
	{
		ll ans=0,j;
		for(j=0;j<(k[i]-'0');j++)
		{
			ans=(ans+solve(k,d,i+1,0,sum+j))%mod;
		}
		ans=(ans+solve(k,d,i+1,1,sum+k[i]-'0'))%mod;
		return(dp[i][tight][sum]=ans%mod);
	}
}
int main()
{
	string k;
	ll d;
	cin>>k>>d;
	memset(dp,-1,sizeof(dp));
	cout<<(solve(k,d,0,1,0)-1+mod)%mod<<"\n";
}