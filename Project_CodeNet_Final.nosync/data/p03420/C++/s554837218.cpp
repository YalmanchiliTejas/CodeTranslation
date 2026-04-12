#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  
  int N, K;
  cin>>N>>K;
  
  int ans = 0;
  
  for(int i=K+1;i<=N;i++){
    
    ans += ( ( N - K ) / i + 1 ) * ( i - K );
    
    if( N % i >= K ) ans -= i - N % i - 1;
    
  }
  
  if( K == 0 ) ans -= N;
  
  cout<<ans<<endl;
  
  return 0;
}
