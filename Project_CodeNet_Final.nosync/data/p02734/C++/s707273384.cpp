#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
int i,a,N,S,ans,v[3001],mod=998244353;
int main(){
  scanf("%d %d",&N,&S);
  while(N--){
    scanf("%d",&a);
    ++v[0];
    for(i=S;i>=a;--i){
      v[i]+=v[i-a];
      v[i]-=(v[i]>=mod)*mod;
    }
    ans+=v[S];
    ans-=(ans>=mod)*mod;
  }
  printf("%d",ans);
}