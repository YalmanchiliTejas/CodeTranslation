#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define n 10005
ll mod=1e9+7;
ll dp[n][105];
ll ans=0;
ll D;
void f(string s,ll p)
{
	if (s.length()==0)
		return;
	ll v=s[0]-'0';
	ll N=s.length();
	if (N==1)
		v++;
	for(ll i=0;i<v;i++)
	{
		ll V=(i%D+p)%D;
		if (N==1)
			V=p%D;
		if (V!=0)
			V=D-V;
		//cout<<i<<" "<<V<<" "<<dp[N-1][V]<<endl;
		if (N>1)
		ans+=(dp[N-1][V]);
		else
		ans+=(i%D==V);
		//cout<<ans<<endl;
		if (ans>=mod)
			ans%=mod;
	}
	s=s.substr(1,N);
	v=(v%D+p)%D;
	f(s,v);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string K;
	cin>>K;
	
	cin>>D;
	ll N=K.length();
	memset(dp,0,sizeof(dp));
	for(ll i=0;i<=9;i++)
		dp[1][i%D]++;
	for(ll i=2;i<=N;i++)
	{
		for(ll j=0;j<D;j++)
		{
			for(ll k=0;k<=9;k++)
			{
				ll v=(k%D+j)%D;
				dp[i][v]+=dp[i-1][j];
				if (dp[i][v]>=mod)
					dp[i][v]%=mod;
			}
		}

	}

	/*
	for(ll i=1;i<=N;i++)
	{	
		for(ll j=0;j<D;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	f(K,0);
	ans=(ans-1+mod)%mod;
	
	cout<<ans;
}