#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define mp make_pair
#define all(a)      (a).begin(),(a).end()
#define debug_array(a,n) for (ll bccc=(0); bccc<(n); bccc++) cout<<a[bccc]<<" "<<"\n"
#define debug_vector(a) for(ll bccc=(0); bccc<(a.size());bccc++) cout<<a[bccc]<<" "<<"\n"
#define F           first
#define S           second
#define debug_set(s) for(auto p:s) cout<<p<<" "
#define debug_map(m) for(auto p:m) cout<<p.F<<" "<<p.S<<"\n"
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl;
typedef long long ll;
using namespace __gnu_pbds;
typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll> >,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
/* ll t = 0;
ordered_multiset me;
...
me.insert({x, t++});
me.erase(me.lower_bound({x, 0}));
cout << me.order_of_key({x, 0}) << "\n";

///////////   t is insertion time
*/
//#pragma GCC optimize("Ofast")  // works very well
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long double lld;
lld pi=3.14159265358;
ll powr(ll a,ll b)
{
    ll c=1;
    ll kjk;
    for(kjk=0;kjk<b;kjk++)
        c*=a;
    return c;
}
ll hell=1000000007;
//ll hell=998244353   ;
ll power(ll x, ll y, ll p)
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
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
// to generate random number , use rng() ... eg cout<<rng();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    ll n,m;
    cin>>n>>m;
    if(n==m)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
