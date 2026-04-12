#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define inf 1000000000000000000
#define bpc(x) __builtin_popcountll(x)
#define autoit(x,it) for(auto it = x.begin(); it != x.end(); it++)
#define rep(n) for(ll i = 0; i < n; i++)
#define repi(i,n) for(ll i = 0; i < n; i++)

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;

#define N 50

int main()
{
   FAST/**/
   
   ll n;
   cin>>n;
   
   ll arr[n+1];
   rep(n)
        cin>>arr[i+1];
   ll dp[n+1][N];
   rep(n+1)
        repi(j,N)
            dp[i][j] = -inf;
            
   dp[1][0] = arr[1];
   dp[1][1] = 0;
   for(ll i=2;i<=n;i++)
   {
       ll maxi = (i+1)/2;
       ll temp = 1;
       if(maxi-temp<N)
            dp[i][maxi-temp] = arr[i];
       for(ll j=i-2;j>max(-1ll,i-5);j--)
       {
           for(ll off = 0;off<N;off++)
           {
               ll tot = (j+1)/2 - off + 1;
               if(maxi-tot>=N)
                    continue;
               dp[i][maxi-tot] = max(dp[i][maxi-tot],dp[j][off]+arr[i]);
           }
       }
   }
   ll ans = -inf;
   ll req = (n)/2;
   for(ll i=1;i<=n;i++)
   {
       for(ll j=0;j<N;j++)
       {
           ll tot = (i+1)/2 - j;
           //cout<<"at "<<i<<" , "<<j<<" = "<<dp[i][j]<<"\n";
           if(tot == req)
                ans = max(ans,dp[i][j]);
       }
   }
   cout<<ans;
   
   
   return 0;        
}  
   