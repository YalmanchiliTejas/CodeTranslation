#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 998244353
#define inf 1000000000000000
#define bpc(x) __builtin_popcountll(x)
#define autoit(x,it) for(auto it = x.begin(); it != x.end(); it++)
#define rep(n) for(ll i = 0; i < n; i++)
#define repi(i,n) for(ll i = 0; i < n; i++)

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;

bool ispa(string s)
{
    ll n = s.length();
    bool pos = 1;
    rep(n)
        if(s[i]!=s[n-1-i])
            pos = 0;
    return pos;        
}

int main()
{
   FAST/**/
   
   ll n,s;
   cin>>n>>s;
   ll arr[n];
   rep(n)
        cin>>arr[i];
   
   ll dp[n][s];
   memset(dp,0,sizeof(dp));
   if(arr[0]<s)
     dp[0][arr[0]] = 1;
   ll ans = 0;
   if(arr[0] == s)
        ans+=n, ans%=mod;        
   for(ll i=1;i<n;i++)
   {
       ll rways = n-i;
       if(s-arr[i]>0){
           ans+=((rways*dp[i-1][s-arr[i]])%mod), ans%=mod;
       }
       if(arr[i] == s)
       {
           ans+=(((i+1)*rways)%mod), ans%=mod;
       }
       for(ll prev = 1;prev<s;prev++)
           dp[i][prev] = dp[i-1][prev];
       if(arr[i]<s){
       dp[i][arr[i]] += (i+1);
       dp[i][arr[i]]%=mod;
       }
       
       for(ll prev = 1;prev<s-arr[i];prev++)
       {
           dp[i][prev+arr[i]]+=dp[i-1][prev];
           dp[i][prev+arr[i]]%=mod;
       }
               
   }
   ans%=mod;
   if(ans<0)
        ans+=mod;
   cout<<ans;
   return 0;        
}  
   