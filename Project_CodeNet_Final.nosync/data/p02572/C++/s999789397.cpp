#include<bits/stdc++.h>
using  namespace  std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define all(x) x.begin(),x.end()
#define nl      '\n'

typedef long long int ll;
typedef unsigned long long int  llu;


int main()
{
	faster
	ll n;
	cin>>n;
	ll a[n+2],i,j,ans=0,sum=0;
	ll pre[n+2];
	ll mx=1e9+7;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		sum%=mx;
	}
	for(i=1;i<=n;i++)
	{
		sum-=a[i];
		if(sum<0)sum+=mx;
		ans+=a[i]*sum;
		ans%=mx;
	}
	cout<<ans<<nl;
	return 0;
	//cout<<ans<<nl;
}
