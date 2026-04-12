#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define pi 3.1415926535897
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
#define mod1 998244353
#define inf 1000000000000000000
#define inf1 1000000000
#define endl '\n'
ll n,d;
ll num[10005];
ll dp[10005][100][2];
ll recurse(ll pos,ll rem,ll bound)
{
	if(dp[pos][rem][bound]!=-1)
		return dp[pos][rem][bound];
	ll lim=((bound==0)?num[pos]:9);
	if(pos==n-1)
	{
		ll ans=0;
		for(ll k=0;k<=lim;k++)
			ans+=((k%d==rem)?1:0);
		return dp[pos][rem][bound]=ans;
	}
	ll ans=0;
	for(ll k=0;k<=lim;k++)
	{
		ll new_rem=(rem-k)%d;
		new_rem=(new_rem+d)%d;
		ll new_bound=bound;
		if(!bound && k<num[pos])
			new_bound=1;
		ans=(ans+recurse(pos+1,new_rem,new_bound))%mod;
	}
	return dp[pos][rem][bound]=ans;
}
int main()
{
	fastio;
	#ifdef APNA_IO
		freopen("input.txt" , "rt" ,stdin);
		freopen("output.txt" , "wt" ,stdout);
	#endif
	string s;
	getline(cin,s);
	cin>>d;
	for(ll i=0;i<s.length();i++)
		num[i]=(ll)s[i]-(ll)'0';
	n=s.length();
	memset(dp,-1,sizeof(dp));
	ll ans=recurse(0,0,0);
	ans=(ans-1)%mod;
	ans=(ans+mod)%mod;
	cout<<ans<<endl;
	return 0;
}