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

ll a,b,c,n,m,k;

ll t=1;

void solve()
{
   cin>>n>>k>>m;
   c=0;
   map<ll,ll>sum,f;
   for(ll i=0;i<n;i++)
   {
       c+=k;
       sum[i]=c;
       k=(k*k)%m;
       
       if(f.find(k)!=f.end())
       {
           ll rest=(n-i-1);
           ll add=(c-sum[f[k]]);
           ll re=(i-f[k]);
           
           c+=((rest/re)*add)+(sum[f[k]+(rest%re)]-sum[f[k]]);
           break;
       }
       else
       {
           f[k]=i;
       }
   }
   cout<<c;
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