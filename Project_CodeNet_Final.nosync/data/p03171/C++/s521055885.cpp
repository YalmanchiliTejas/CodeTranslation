//i ll be the king
#include<bits/stdc++.h>
#define ll long long int
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define rep(n) for(ll i2=0;i2<n;i2++)
#define vmp(v,a,b) v.push_back(make_pair(a,b))
#define si(a) scanf("%lld",&a)
#define pi(a) printf("%lld",a)
#define aset(a,n,k) for(ll i3=0;i3<n;i3++)a[i3]=k; 	
#define mod 1000000007
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define f first
#define s second
using namespace std;	

int main()
{
	sync;
	ll n;
	cin>>n;
	ll arr[n+1];
	for(ll i=1;i<=n;i++)cin>>arr[i];
	pair<ll,ll> dp[n+1][n+1];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j+i<=n+1;j++)
		{
			ll ind=j+i-1;
			if(ind==j)
			{
				dp[j][ind].f=arr[j];
				dp[j][ind].s=0;
			}
			else
			{
				dp[j][ind].f=max(arr[j]+dp[j+1][ind].s,arr[ind]+dp[j][ind-1].s);
				dp[j][ind].s=arr[j]+dp[j+1][ind].f+dp[j+1][ind].s-dp[j][ind].f;
			}
		}
	}
	cout<<dp[1][n].f-dp[1][n].s;
}

