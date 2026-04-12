#define ll long long
#define pb push_back
#define make_pair mp
#define first f
#define second s
#define upper_bound ub
#define lower_bound lb
#define MOD 1000000007
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;


#define ordered_set tree<pair<ll,ll> , null_type,less<pair<ll,ll> >, rb_tree_tag,tree_order_statistics_node_update>ll fn



void solve(){
    ll n;cin>>n;
    ll a[n+1],ps[n+1];
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    ps[n]=0;
    for(ll i=n-1;i>=1;i--){
        ps[i]=ps[i+1]+a[i+1];
        ps[i]%=MOD;
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans += (ps[i]*a[i])%MOD;
        ans%=MOD;
    }
    cout<<ans;
}

int main ()
{
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  ll t;
  //cin>>t;
  t = 1;
  while (t)
    {
      solve();t--;
      //cout<<"end of test case"<<endl;
    }
  return 0;
}
