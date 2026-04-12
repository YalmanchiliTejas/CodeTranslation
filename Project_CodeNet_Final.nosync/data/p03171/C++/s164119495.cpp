#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ld long double
#define dd double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef vector<pll> vplll;
ll mod = 1e9+7;
const ld PI = 2 * acos(0.0);
const vector<ll> dx = {1, -1, 0, 0};
const vector<ll> dy = {0, 0, 1, -1};
#define round(x, y) ((x + y - 1) / y)
#define ce(x, y) ((x + y - 1) / y)
#define amax(x, y) \
    if (y > x)     \
        x = y;
#define amin(x, y) \
    if (y < x)     \
        x = y;
#define lcm(x, y) ((x) * (y) / __gcd(x, y))
#define len(x) (ll) x.length()
#define sq(x) ((x) * (x))
#define cb(x) ((x) * (x) * (x))
ll dp[3001][3001];
int ar[3001];
int n;
ll x = 0, y = 0, fl = 0;
ll count(int i, int j)
{
	if(i==j)
		return dp[i][j] = ar[i];
	if(i==j-1)
		return dp[i][j] = max(ar[i],ar[j]);
	if(dp[i][j]!=0)
		return dp[i][j];
	fl++;
	fl %= 2;
	ll l1, l2, l3, ans;
	l1 = count(i+2,j);
	l2 = count(i,j-2);
	l3 = count(i+1,j-1);
	l1 = min(l1,l3);
	l2 = min(l2,l3);
	// ans = (l1+ar[i],l2+ar[j]);
	ans = max(l1+ar[i],l2+ar[j]);
	// ans = max(ans,ar[i]+l3);
	// ans = max(ans,ar[j]+l3);
	if(fl)
		x+=ans;
	else
		y+=ans;
	return	dp[i][j] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c,t,m,k,q; 
    t = 1;
    // cin>>t;
    while(t--)
    {
    	cin>>n;
    	ll sum=0;
    	for(int i=0;i<n;i++)
    	{
    		cin>>ar[i];
    		// ar.pb(a);
    		sum += ar[i];
    	}
    	ll ans = count(0,n-1);
    	cout<<2*ans-sum<<endl;
    }
    return 0;
}