#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int main(){
  ll N,i,ans = 0,now = 0;scanf("%lld",&N);
  ll A[N];
  for(i=0;i<N;i++) scanf("%lld",&A[i]);
  now = A[N-1];
  for(i=N-2;i>=0;i--){
    ans = (ans+A[i]*now%mod)%mod;
    now = (now+A[i])%mod;
  }
  printf("%lld\n",ans);
}