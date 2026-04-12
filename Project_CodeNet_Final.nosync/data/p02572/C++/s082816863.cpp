#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#ifndef ONLINE_JUDGE
#define OJ \
    freopen("input.txt", "r", stdin); \
    //freopen("output.txt", "w", stdout);
#else
#define OJ ;
#endif
#define fo(int, i, l, r) for ( int i = l ; i < r ; ++ i)
#define srtV(a) sort(a.begin(),a.end())
const ll mod = 1e9+7;
ll minv (ll x)
{
    ll p=mod-2;
    ll ans=1,xx=x;
    while(p>0)

    {
        if(p&1)
            ans=(ans*xx)%mod;
        xx=(xx*xx)%mod;
        p=p/2;
        

    }
    return ans;
}

void solve()
{
    ll n;
    cin>>n;
    vector <ll> sq(n,0ll),a(n,0ll);
    ll sum=0,sumSq=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        sq[i]=(a[i]*a[i])%mod;
        sum=(sum+a[i])%mod;
        sumSq=(sumSq+sq[i])%mod;
    }

    cout<<(((((sum*sum)%mod)- sumSq +mod )%mod)*(500000004ll))%mod<<"\n";


}
signed main()
{
    OJ
    //cout<<minv(2)<<"\n";
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //int _t;cin>>_t;while(_t--)
    solve();
    return 0;
}