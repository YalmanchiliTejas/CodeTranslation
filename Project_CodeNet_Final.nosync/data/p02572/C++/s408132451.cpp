#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod  = 1e9+7;
int32_t  main(){
     int n;
     cin>>n;
     int a[n];
     int k[n+1]= {0};
     for(int i=0;i<n;++i){
         cin>>a[i];
     }
     int sum = a[n-1]% mod ;
     for(int i=n-1;i>=0;--i){
            k[i] =(  (a[i] % mod) +(k[i+1]% mod ) ) % mod ;
     }
    //  for(int i=0;i<n;++i){
    //      cout<<a[i]<<" ";
    //  }
     int ans= 0 ;
     for(int i=0;i<n-1;++i){
         ans=    (ans+ ( a[i]* k[i+1])% mod )  %mod;
         ans %= mod;
     }
     cout<<ans % mod;;
    
}