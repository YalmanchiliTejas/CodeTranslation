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
  int n;
  cin>>n;
  int h[n];
  int cur=0;
  for(int i=0;i<n;i++){
    cin>>h[i];
    bool ans=true;
    for(int j=0;j<i;j++){
      if(h[j]>h[i]) ans=false;
    }
    if(ans) cur++;
  }
  cout<<cur<<endl;
  return 0;
}
