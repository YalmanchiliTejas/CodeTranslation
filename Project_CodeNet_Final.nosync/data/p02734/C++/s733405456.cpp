#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
int i,a,N,S,ans,v[3001],mod=998244353;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>N>>S;
  while(N--){
    cin>>a;
    ++v[0];
    for(i=S;i>=a;--i){
      v[i]+=v[i-a];
      v[i]-=(v[i]>=mod)*mod;
    }
    ans+=v[S];
    ans-=(ans>=mod)*mod;
  }
  cout<<ans;
}