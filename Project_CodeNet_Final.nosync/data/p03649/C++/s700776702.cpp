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
const int M=52;
ll a[M],ct[M];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll ans=0;
	while(1)
	{
		ll res = 0;
		for(int i=1;i<=n;i++)
		{
			ct[i]=(a[i])/n;
			a[i]%=n;
			res = res + ct[i];
		} 
		if(res==0)
			break;
		for(int i=1;i<=n;i++)
			a[i]=a[i]+res-ct[i];
		ans+=res;
	}
	multiset<ll> mlt;
	for(int i=1;i<=n;i++)
		mlt.insert(a[i]);
	while(sz(mlt))
	{
		auto it=mlt.begin();
		ll z=*it;
		mlt.erase(it);
		if(z<n)
			break;
		z=z-n;
		mlt.insert(z);
		ans++;
	}
	cout<<ans<<"\n";
	return 0;
}