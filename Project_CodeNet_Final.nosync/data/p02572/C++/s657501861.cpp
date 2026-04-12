#include<bits/stdc++.h>
using namespace std;
#define hackcyborg shresth_walia
#define ll long long
#define ld double
#define pb push_back
#define mod 1000000007
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
ll binpow(ll a,ll b,ll m=mod)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
        res=(a*res)%m;
        a=(a*a)%m;
        b/=2;
    }
    return res;
}
main()
{
    IO
    ll ans=0;
    ll n;
    cin>>n;
    ll a;
    ll s=0;
    for(int x=0;x<n;x++)
    {
        cin>>a;
        ans=(ans+(s*a))%mod;
        s+=a;
        s%=mod;
    }
    cout<<ans;
}
