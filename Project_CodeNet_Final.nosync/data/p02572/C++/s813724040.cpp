#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int main() {
  ll MOD=1000000007;
  int n;
  cin>>n;
  ll a[n],s[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(i==0) s[i]=a[i];
    else s[i]=mod(s[i-1]+a[i],MOD);
  }
  ll ans=0;
  for(int i=1;i<n;i++){
    ans+=a[i]*s[i-1];
    ans=mod(ans,MOD);
  }
  cout<<ans<<endl;
  return 0;
}
