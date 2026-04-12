#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
int64_t MOD=1000000007;

int main() {
  int64_t N,K,ans=0,zero=0;
  cin>>N>>K;
  if(K==0) ans=N*N;
  else{
    for(int b=K+1;b<=N;b++){
    ans+=(b-K)*(N/b);
    if(N%b>=K) ans+=N%b-K+1;
    }
  }
  cout<<ans;
}
