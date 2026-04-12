#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll dp[100000+10][2][105];
string s;
int d;
ll digit_dp(ll pos, ll tgt, ll sum)
{
	if(pos==(ll)s.size())
	{
		if(sum==0)
			return 1ll;
		return 0ll;
	}
	if(dp[pos][tgt][sum]!=-1)
	return dp[pos][tgt][sum];
	
	ll ans=0;
	if(tgt==1)
	{
		for(int i=0;i<=s[pos]-'0';i++)
		{
			if(i==s[pos]-'0')
				ans = ans + digit_dp(pos+1,1,(sum+i)%d);
			else
				ans = ans + digit_dp(pos+1,0,(sum+i)%d);
			
			ans=ans%mod;
		}
		
	}
	else
	{
		for(int i=0;i<=9;i++)
		{
			ans = ans + digit_dp(pos+1, 0, (sum+i)%d);
			ans=ans%mod;
		}
	}
	return dp[pos][tgt][sum]=ans%mod;
	
}

int main()
{
	cin>>s;
	cin>>d;
	memset(dp,-1,sizeof(dp));
	
	ll ans = digit_dp(0,1,0)-1ll;
	if(ans==-1)
	ans=mod-1;
	
	cout<<ans;
} 
