#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int N,K;
  cin>>N>>K;
  int o=0;
  if(K==0)cout<<N*N<<endl;
  else{
    int ans=0;
    ans+=(N-K+1)*(N-K);
    ans/=2;
    for(int b=K+1;b<=N;b++){
      ans+=max((N/b-1)*(b-K),o);
      ans+=max((N%b)-K+1,o);
    }
    cout<<ans<<endl;
  }
  return 0;
}
