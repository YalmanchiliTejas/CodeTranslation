#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll dp[100001][104][2];
// map< pair<ll,pair<ll,ll> > mp;
ll go(string str,ll d,ll pos=0,ll rem=0,ll tight=1)
{
	if(pos==str.length())
	{
		if(rem==0)
			return 1;
		else
			return 0;
	}
	else if(dp[pos][rem][tight]!=-1)
		return dp[pos][rem][tight];
	else if(tight==1)
	{
		ll res=0;
		for(ll i=0;i<=str[pos]-'0';i++)
		{
			if(i==str[pos]-'0')
				res=(res%mod+go(str,d,pos+1,(rem+i)%d,1)%mod)%mod;
			else
				res=(res%mod+go(str,d,pos+1,(rem+i)%d,0)%mod)%mod;
		}
		if(res<0)
			res+=mod;
		return dp[pos][rem][tight]=res%mod;	
	}
	else
	{
		ll res=0;
		for(int i=0;i<=9;i++)
			res=(res%mod+go(str,d,pos+1,(rem+i)%d,0)%mod)%mod;
		if(res<0)
			res+=mod;
		return dp[pos][rem][tight]=res%mod;
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string k;
	cin>>k;
	ll d;
	cin>>d;
	memset(dp,-1,sizeof(dp));
	cout<<(go(k,d)-1+mod)%mod<<endl;
}
