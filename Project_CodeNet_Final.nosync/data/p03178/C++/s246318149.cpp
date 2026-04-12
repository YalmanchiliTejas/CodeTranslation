#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define M 1000000007
#define sz(a) (ll)a.size()
#define pll pair<ll,ll>
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define sep(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define mll map<ll,ll>
#define vl vector<ll>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define F first
#define S second
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
string k;
ll d,dp[10005][2][105];
ll f(ll pos,ll flag,ll r)
{
	if(pos==sz(k))
		return r==0;
	if(dp[pos][flag][r]!=-1)
		return dp[pos][flag][r];
	ll ans=0;
	if(flag)
	{
		ll e=(k[pos]-'0');
		rep(i,0,e)
			ans=(ans+f(pos+1,0,(r+i)%d))%M;
		ans=(ans+f(pos+1,1,(r+e)%d))%M;
	}
	else
	{
		rep(i,0,10)
			ans=(ans+f(pos+1,0,(r+i)%d))%M;
	}
	dp[pos][flag][r]=ans;
	return ans;	
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>k>>d;
    cout<<(f(0,1,0)+M-1)%M;
}
