#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define frw(i, a, b) for(int i = a; i < b; i++)
#define fi first
#define se second
#define pb push_back
#define in insert
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) int(a.size())
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define plll pair<ll, pll>
#define vpii vector<pii>
#define vpiii vector<piii>
#define vpll vector<pll>
#define vplll vector<plll>
#define mod 1000000007

int modInverse(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) 
      return 0; 
    while (a > 1) 
    { 
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
    return x; 
} 


int main() {
	int n;
	cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];

	}
	reverse(a.begin(),a.end());
	vector<ll> d(n,mod);
	for(int i=0;i<n;i++)
	{
		int u=upper_bound(d.begin(),d.end(),a[i])-d.begin();
		d[u]=a[i];
	}
	ll ans=-1;
	for(int i=0;i<n;i++)
	{
		if(d[i]==mod)
		{
			ans=i;
			break;
		}
	}
	if(ans==-1)
		ans=n;
	cout<<ans;

	
}
