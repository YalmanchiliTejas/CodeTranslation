#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"
#define llevel 20
ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
string s;
ll d,n;
const int  N=10005;
ll dp[N][100][2];
ll solve(ll pos,ll sum,ll prev)
{
	if(pos==n)
	{
		return (sum==0);
	}
	if(dp[pos][sum][prev]!=-1)return dp[pos][sum][prev];
	ll ans=0;
	ll num=9;
	if(prev==1)
		num=s[pos]-'0';
	for(ll j=0;j<=num;++j)
	{
		ll ff=0;
		if(j==num && prev==1)ff=1;
		ans+=solve(pos+1,(sum+j)%d,ff);
		ans%=M;
	}
	return dp[pos][sum][prev]=ans;
}
int _runtimeTerror_()
{
	cin>>s>>d;
	n=s.length();
	mem1(dp);
	cout<<(solve(0,0,1)-1+M)%M;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef runSieve
		sieve();
	#endif
	#ifdef NCR
		initialize();
	#endif
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}
