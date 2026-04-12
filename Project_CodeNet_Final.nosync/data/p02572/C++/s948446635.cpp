#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(),v.end()
#define repf(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define MOD 998244353 

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<ll> ors;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll power(ll a, ll n, ll m)
{
    ll ans=1;
    while(n)
    {
        if(n&1) ans=(ans*a)%m;
        n>>=1;
        a=(a*a)%m;
    }
    return ans;
}

ll invmod(ll a, ll m)
{
    return power(a,m-2,m);
}

void solve(ll tt) {
    ll n;
    cin>>n;
    ll a[n];
    repf(i,0,n) cin>>a[i];
    ll suf[n];
    suf[n-1]=a[n-1];
    repb(i,n-2,0) suf[i]=(suf[i+1]+a[i])%mod;
    ll ans=0;
    repf(i,0,n-1) {
        ans=(ans+(a[i]*suf[i+1])%mod)%mod;
    }
    cout<<ans<<endl;
} 

int main()
{
    IOS;
    ll t;
    // cin>>t;
    t=1;
    repf(tt,1,t+1) {
        solve(tt);
    }
}     