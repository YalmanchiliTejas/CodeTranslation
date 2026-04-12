#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n,m,x,suma;
vector<ll> vals;
ll f[500001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>x>>m;
    vals.push_back(x);
    suma=x;
    n--;
    f[x]=1;
    ll val=x;
    int poz=1;
    while(n>0)
    {
        val=(val*val)%m;
        poz++;
        if(val==0)
        {
            cout<<suma;
            return 0;
        }
        if(f[val]>0)
        {
            poz=f[val];
            break;
        }
        f[val]=poz;
        vals.push_back(val);
        suma+=val;
        n--;
    }
    if(n==0)
    {
        cout<<suma;
        return 0;
    }
    ll ans=suma;
    vector<ll> v;
    for(int i=poz-1;i<vals.size();i++)
        v.push_back(vals[i]);
    suma=0;
    for(auto i:v)
        suma+=i;
    ll lg=v.size();
    ll cat=n/lg;
    ans+=cat*suma;
    ll rest=n%lg;
    for(int i=0;i<rest;i++)
        ans+=v[i];
    cout<<ans;
    return 0;
}
