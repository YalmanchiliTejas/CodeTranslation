#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
ll Layer[51],Patty[51];
void init(){
  ll i;
  Layer[0] = Patty[0] = 1;
  for(i=1;i<=50;i++){
    Layer[i] = Layer[i-1]*2+3;
    Patty[i] = Patty[i-1]*2+1;
  }
}
ll PattyCount(ll level,ll X){
  if(level == 0) return X == 1;
  if(X <= 1) return 0;
  X--;
  ll ans = 0;
  if(X >= Layer[level-1]){
    ans += Patty[level-1];
    X -= Layer[level-1];
  } else return PattyCount(level-1,X);
  if(X == 0) return ans;
  X--;ans++;
  if(X == 0) return ans;
  if(X >= Layer[level-1]){
    ans += Patty[level-1];
    X -= Layer[level-1];
  } else return ans+PattyCount(level-1,X);
  return ans;
}
int main(){
  init();
  ll N,X;scanf("%lld%lld",&N,&X);
  printf("%lld\n",PattyCount(N,X));
}