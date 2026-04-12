#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size() 

ll ans=0,MD=998244353,n;
ll a[3005],s;
ll dp[3005][3005],vis[3005][3005];
ll solve(ll idx,ll sum)
{
	if(idx==n)
	{
		// cout<<sum<<" "<<idx<<endl;
		ll r1=0;
		if(sum==a[idx])
			r1=(r1+1)%MD;
		if(sum==s)
		{
			// if(sum==4)
			ans=(ans+(idx*r1)%MD)%MD;
			// cout<<ans<<endl;
		}
		return dp[idx][sum]=r1;
	}
	
	if(vis[idx][sum])
		return dp[idx][sum];
	
	vis[idx][sum]=1;
	ll r1=0;
  	if(sum>=a[idx])
		r1=(r1+solve(idx+1,sum-a[idx]))%MD;
	ll r2=solve(idx+1,sum);

	if(sum==a[idx])
		r1=(r1+n-idx+1)%MD;

	if(sum==s)
		ans=(ans+(idx*r1)%MD)%MD;

	r1=(r1+r2)%MD;
	return dp[idx][sum]=r1;
}


int main()
{
    ios_base::sync_with_stdio(false);
	ll i,j,k,x,y,t,m;

	cin >> n >> s;
	for(i=1;i<=n;i++)
		cin >> a[i];

	solve(1,s);
	cout<<ans<<endl;
}
