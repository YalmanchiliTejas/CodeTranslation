#include "bits/stdc++.h"
using namespace std;
#pragma GCC optimize "trapv"
#define pb push_back
#define fi first
#define se second
#define all(container) container.begin(),container.end()
#define fast ios::sync_with_stdio(0); cin.tie(0)
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#endif
#define int long long
const int mod = 1e9+7;  
int power(int a,int b) { if(b==0) return 1; int res = power(a,b/2); if(b&1) return res * res * a; else return res * res; }


int32_t main(){
    
  fast;
  int n; cin >> n;
  int ar[n] = {0};

  for(int i=0;i<n;i++){
    cin >> ar[i];
  }

  int suffix[n] = {0};
  int mod = 1e9+7;

  suffix[n-1] = ar[n-1]%mod;

  for(int i=n-2;i>=1;i--){
    suffix[i] = (suffix[i+1]%mod + ar[i]%mod)%mod;
  }

  int ans = 0;
  

  for(int i=0;i<n-1;i++){
    ans = ans + (ar[i]%mod*suffix[i+1])%mod;
    ans%=mod;
  }

  cout << ans << '\n';

  return 0;
}