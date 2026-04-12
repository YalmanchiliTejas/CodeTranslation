#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
using namespace __gnu_pbds;  
using namespace std;

typedef tree<long long, null_type, less<long long>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    new_data_set; 
    
//defines
typedef long long ll;
typedef long double ld;
const long long MOD = (long long)(1e9 + 7); //(int)(1e9 + 7); //998244353;

ll a,b,c,n,m,k;

ll t=1;


void solve()
{
    cin>>n;
    vector<ll>v(n);
    ll sum=0LL;
    for(ll i=0;i<n;i++)cin>>v[i],sum+=v[i];
    ll ans=0LL;
    for(ll i=0;i<n-1;i++)
    {
        sum-=v[i];
        ans+=((v[i]*(sum%MOD))%MOD);
        ans%=MOD;
    }
    cout<<ans;
 if(t>0)cout<<"\n";
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  //cin>>t;
    while(t--)
    {
        solve();
    }
  //cout<<sum;
        
    return 0;
}