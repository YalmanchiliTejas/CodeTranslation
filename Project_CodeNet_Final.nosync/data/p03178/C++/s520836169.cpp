#include<bits/stdc++.h>
typedef  long long int ll;
typedef  long double ld;
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define mod 1000000007
#define F first
#define S second 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
//recursions\
#pragma comment(linker, "/stack:200000000")
//loops\
#pragma GCC optimize("unroll-loops")
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_order(ind)
using namespace std;
ll dp[10001][2][100];
vector<ll>num;
ll calc(ll idx,ll d,ll bnd,ll sum)
{
	if(idx==-1)
	return sum==0;
	
	if(dp[idx][bnd][sum]!=-1)
	return dp[idx][bnd][sum];
	
	ll k=bnd?num[idx]:9;
	
	ll ans=0;
	for(ll i=0;i<=k;i++)
	{
		ll nbnd=(i==k)?bnd:0;
		ans+=calc(idx-1,d,nbnd,(sum+i)%d);
		ans%=mod;
	}
	
	return dp[idx][bnd][sum]=ans;
	
}
ll solve(string k,ll d)
{
	memset(dp,-1,sizeof(dp));
	ll x=k.size()-1;
	while(x>=0)
	{
		num.push_back(k[x]-'0');
		x--;
	}
	return calc(num.size()-1,d,1,0);
}
int main()
{
	sync;
	ll d;
	string k;
	cin>>k>>d;
	cout<<(solve(k,d)+mod-1)%mod;
}
	
