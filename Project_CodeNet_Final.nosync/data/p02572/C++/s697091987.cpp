//@sakshjha
#include<bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

#define ll long long  int
#define ld long double
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pi 3.14159265358979
#define pa pair<ll,ll>
//#define goodset tree<pa, null_type, less<pa>, rb_tree_tag, tree_order_statistics_node_update>
//#define FRE freopen("acm.in","r",stdin); freopen("acm.out","w",stdout);

const ll mod = 1e9+7 ;
const ll N = 1e4+2;

//vector<ll>dp[N];
vector<ll>v;
int main()
{
    ll i,j,k,tc;
    //cin>>tc;
    tc=1;
    while(tc--)
    {
       ll n;
       cin>>n;
       ll a[n];
       ll sum=0;
       for(i=0; i<n; i++)
       {
           cin>>a[i];
           sum+=a[i];
           sum%=mod;
       }
       ll ans=0;
       //cout<<sum<<"\n";
       for(i=0; i<n; i++)
       {
           ll val=a[i];
           ll val1=(sum-a[i]+mod)%mod;
           val*=val1;
           val%=mod;
           ans+=val;
           ans%=mod;
            //cout<<ans<<"\n";
           sum=(sum-a[i]+mod)%mod;
       }
       cout<<ans;
    }

    return 0;
}
