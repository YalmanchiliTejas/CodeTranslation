#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;
const ll mod=1000000007;
ll pow(ll x,ll y){
  ll res=1;
  for(ll i=0;i<y;i++){
    res*=x;
  }
  return res;
}

ll powmod(ll x,ll y){
  ll res=1;
  for(ll i=0;i<y;i++){
    res=res*x%mod;
  }
  return res;
}

main(){
  ll n;cin >> n;
  ll a[n];for(ll i=0;i<n;i++) cin >> a[i];
  ll f=0;
  for(ll i=0;i<n;i++){
    f+=a[i];
    f%=mod;
  }
  ll ans=0;
  for(ll i=0;i<n;i++){
    f-=a[i];
    if(f<0) f+=mod;
    ans+=f*a[i];
    ans=(ans+mod)%mod;
  }
  cout << ans << endl;
  return 0;
}