#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007


int32_t main(){
    int n; cin>>n; vector <int> a(n),pref(n); for(int i=0 ; i<n ; i++) cin>>a[i];
    pref[0] = a[0];
    for(int i=1 ; i<n ; i++) pref[i] = (pref[i-1]+a[i])%mod;
    
    int ans =0;
    for(int i=0 ; i<n-1 ; i++){
       ans = (ans + ((a[i]%mod)* ((pref[n-1]-pref[i]+mod)%mod))%mod)%mod; 
    }
      cout<<ans;
}