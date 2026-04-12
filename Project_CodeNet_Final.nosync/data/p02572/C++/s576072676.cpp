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

ll power(ll x,ll y,ll p) 
{ 
    ll res = 1;      
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p;   
    } 
    return res; 
} 
ll a[500005];
ll md=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
	ll n,i,j,k,x=0,y,t,m;

	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> a[i];
		x+=a[i];
		x%=md;
	}
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		y=(x-a[i]+md)%md;
		ans+=(a[i]*y)%md;
		ans%=md;
	}
	cout<<(power(2,md-2,md)*ans)%md<<endl;
}