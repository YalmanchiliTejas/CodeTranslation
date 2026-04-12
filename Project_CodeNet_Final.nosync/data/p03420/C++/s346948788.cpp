
#include<bits/stdc++.h>
using namespace std;
int main(){
  long N,K;cin>>N>>K;
  if(K==0){cout<<N*N;return 0;}
  long ans=0;
  for(long b=K+1;b<=N;b++){
    long Q=N/b;
    long x=Q*(b-K);
    long y=max(0L,N-(b*Q+K)+1);
    ans+=x+y;
  }
  cout<<ans;
}