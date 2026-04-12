#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
int main(){
  ll N,X,M,i,ans = 0;scanf("%lld%lld%lld",&N,&X,&M);
  ll last[M];fill(last,last+M,-1);
  vector<ll> num;
  num.emplace_back(X);
  last[X] = 0;
  ans += X;
  for(i=1;i<N;i++){
    X = X*X%M;
    if(last[X] != -1) break;
    last[X] = i;
    ans += X;
    num.emplace_back(X);
  }
  if(i == N){
    printf("%lld\n",ans);return 0;
  }
  N -= i;
  ll ssum = 0,sturn = num.size()-last[X];
  for(i=last[X];i<num.size();i++) ssum += num[i];
  ans += ssum*(N/sturn);
  N %= sturn;
  ans += accumulate(num.begin()+last[X],num.begin()+last[X]+N,0LL);
  printf("%lld\n",ans);
}