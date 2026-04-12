/* BABA JAGAAAAAA  */  

#include<bits/stdc++.h>
#define pb push_back
#define un unordered_map
#define us unordered_set
#define ll long long
#define fast ios:: sync_with_stdio(false);cin.tie(NULL)
#define l long 
using namespace std;
const int  mod= 1e9+7;
const int inf=1e9+3;

 int main()
 {
     fast;  
    // 3rd//
    ll n;
    cin>>n;
    vector<ll>v(n);
     for(int i=0; i<n; i++)
     cin>>v[i];
      ll sum[n];
      sum[n-1]=v[n-1];
       for( ll i=n-2; i>=0; i--)
       {
           sum[i]=(sum[i+1]+v[i])%mod;
       }
      ll ans=0;
       for(ll  i=0;  i<n-1; i++)
       {
           ans=(ans%mod+(v[i]*sum[i+1]))%mod;
       }
        cout<<ans<<endl;
       
    
 
       return 0;
     
 }
  