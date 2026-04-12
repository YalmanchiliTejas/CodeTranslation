#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
const ll M=3002;
const ll mod=998244353;
ll a[M];
ll dp[M],tp[M];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,s;
	cin>>n>>s;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	ll ans=0;
	dp[0]=1;
	for(ll i=1;i<=n;i++)
	{
		memset(tp,0,sizeof(tp));
		tp[a[i]]=i;
		for(ll j=a[i]+1;j<=s;j++)
			tp[j] = dp[j-a[i]];
		for(ll j=0;j<=s;j++)
			dp[j]=(dp[j]+tp[j])%mod;
		ans=(ans+dp[s])%mod;
	}
	cout<<ans<<"\n";
	return 0;
}