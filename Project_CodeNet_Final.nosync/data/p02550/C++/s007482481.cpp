#include<bits/stdc++.h>
using namespace std;
#define hackcyborg shresth_walia
#define ll long long
#define ld double
#define pb push_back
#define mod 998244353
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define ordered_set tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
ll bp(ll a,ll b,ll m=mod)
{
    ll res=1;
    if(b<0)
        return bp(bp(a,m-2),-b);
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
    ll n,g,m;
    cin>>n>>g>>m;
    ll po[m+1];
    memset(po,-1,sizeof(po));
    vector<ll> as;
    as.pb(0);
    ll a=g;
    as.pb(g);
    ll l=g;
    po[l%m]=1;
    ll v=1;
    for(int x=2;x<=n;x++)
    {
        ll e=((l%m)*(l%m))%m;
        if(po[e]==-1 || v==0)
          {a+=e;
          l=e;
          po[e]=x;
          as.pb(e);
          }
          else
          {  // cout<<e<<" "<<po[e]<<" "<<x<<"\n";
              ll k=0;
              v=0;
              for(int y=po[e];y<x;y++)
              {
                  k+=as[y];
              }
              ll h=((n-x+1)/(x-po[e]));
              a+=(((n-x+1)/(x-po[e]))*k);
              x+=(h*(x-po[e]))-1;
              //cout<<h<<" "<<x<<"\n";
          }
    }
    cout<<a;
}
