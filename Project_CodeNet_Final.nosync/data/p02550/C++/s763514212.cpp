#define ll long long
#define pb push_back
#define make_pair mp
#define first f
#define second s
#define upper_bound ub
#define lower_bound lb

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;


#define ordered_set tree<pair<ll,ll> , null_type,less<pair<ll,ll> >, rb_tree_tag,tree_order_statistics_node_update>

void solve(){
    ll n,x,m;
    cin>>n>>x>>m;
    if(n==1){
        cout<<x;return;
    }
    ll ps[100005];
    memset(ps,0,sizeof(ps));
    ps[1]=x;
    map<ll,ll> ma;
    ma[x]=1;
    ll ans=x;
    ll ci=2,pe=x;
    for(;ci<=n;ci++){
        ll ce = (pe*pe)%m;
        if(ma.count(ce)>0){
            break;
        }
        else if(ce==0){
            cout<<ans;return;
        }
        else{
            ma[ce]=ci;ans+=ce;
        }
        ps[ci]=ps[ci-1]+ce;
        pe=ce;
    }
    cout<<endl;
    if(ci<n){
        ci--;
        ll ce = (pe*pe)%m;
        ll len = ci - ma[ce] + 1;
        ans += (ps[ci]-ps[ci-len])*((n-ci)/(len));
        ll rem_len=(n-ci)%len;
        ans += (ps[ci-len+rem_len]-ps[ci-len]);
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
