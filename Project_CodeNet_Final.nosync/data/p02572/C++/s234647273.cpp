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
const ll mod = 1e9+7;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll res = 0;
	ll s = 0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		res = (res + s*x)%mod;
		s = (s+x)%mod;
	}
	cout<<res<<"\n";
	return 0;
}