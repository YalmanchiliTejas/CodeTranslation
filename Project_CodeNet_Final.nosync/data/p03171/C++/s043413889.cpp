#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inf 922337203685477580
#define mini 9223372036854775807
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
pair<ll,ll>s4[4]={{-1,0},{1,0},{0,-1},{0,1}};
pair<ll,ll>s8[8]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,1},{1,0},{1,-1}};
ll power(ll a,ll b)
{
	if(b==0)
		return 1;
	ll c=power(a,b/2);
	if(b%2==0)
		return ((c%mod)*(c%mod))%mod;
	else
		return ((((c%mod)*(c%mod))%mod)*a)%mod;
}
ll n;
ll dp[3001][3001];
ll a[3005];
ll func(ll start,ll end)
{
	if(dp[start][end]!=-1)
		return dp[start][end];
	ll size=end-start+1;
	ll x=n-size;
	ll ch=x%2;
	ll ans1,ans2;
	if(start==end)
	{
		if(ch==0)
			return dp[start][end]=a[start];
		else
			return dp[start][end]=-1*a[start];
	}
	if(ch==0)
	{
		ans1=a[start]+func(start+1,end);
		ans2=a[end]+func(start,end-1);
		dp[start][end]=max(ans1,ans2);
	}
	else
	{
		ans1=func(start+1,end)-a[start];
		ans2=func(start,end-1)-a[end];
		dp[start][end]=min(ans1,ans2);
	}
	return dp[start][end];
}
int main()
{
	boost
	cin>>n;
	ll i,j;
	for(i=0; i<3001; i++)
		for(j=0; j<3001; j++)
			dp[i][j]=-1;
	for(i=0; i<n; i++)
		cin>>a[i];
	ll ans=func(0,n-1);
	cout<<ans<<endl;
	return 0;
}