#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef long double ld;

#define llset tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define en '\n'
#define S second
#define F first
#define pll pair<ll,ll>
#define PB push_back

const ll N = 1e6+7;
ll mod = 1e9+7;
#define calncr for(int i=1  ;i<=1e6;i++) fac[i] = (fac[i-1]*i)%mod;
ll fac[N] = {0};

ll gen_base(const ll before, const ll after) {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt_rand(seed);
    int base = std::uniform_int_distribution<ll>(before+1, after)(mt_rand);
    return base % 2 == 0 ? base-1 : base;
}

ll pow(ll a,ll b)
{
    if(!b)
        return 1;
    ll p = pow(a,b/2);
    if(b%2)
        return (a*((p*p)%mod))%mod;
    else
        return (p*p)%mod;
}

ll modInv(ll a)
{
    //cout<<a<<" "<<mod<<en;
    return pow(a%mod,mod-2);
}

ll nCr(ll n,ll r)
{
    return (fac[n]*modInv((fac[r]*fac[n-r])%mod))%mod;
}

ll hashf(ll r,ll x,ll mod)
{
    return (x+r)%mod;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    fac[0] = 1;
    calncr;
    ll n;
    cin>>n;
    ll arr[n],sm=0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        sm = (sm+arr[i])%mod;
    }
    ll ans=0;
    for(ll i=1;i<n;i++){
        sm = (sm-arr[i-1]+mod)%mod;
        ans = (ans+(sm*arr[i-1])%mod)%mod;
    }
    cout<<ans;
}
