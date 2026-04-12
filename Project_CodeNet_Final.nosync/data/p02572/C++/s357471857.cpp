#include<bits/stdc++.h>
using namespace std;
using UL=unsigned int;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
 const LL M = 1000000007;
 LL ans = 0;
 LL d = 0;
 int N; scanf("%d",&N);
 rep(i,N){
  LL a; scanf("%lld",&a);
  ans += d*a%M;
  d = (d+a)%M;
 }
 ans %= M;
 printf("%lld\n",ans);
 return 0;
}