#include <bits/stdc++.h>
using namespace std;

int main() {
  long N,K;
  cin>>N>>K;
  long ans=0;

  for(long b=K+1;b<=N;b++){
    long p=N/b;
    long r=N%b;
    ans += max(long(0),b-K)*(p);
    ans+= max(long(0),r-K+1);
    if(K==0) ans--;
  }


  cout<<ans<<endl;
}
