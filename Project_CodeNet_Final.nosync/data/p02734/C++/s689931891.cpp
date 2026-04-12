#include<bits/stdc++.h>
using namespace std;
int main(){
  long long i,N,S,a,ans=0;
  cin>>N>>S;
  vector<int> v(S+1,0);
  while(N--){
    cin>>a;
    ++v[0];
    if(S>=a)(ans+=v[S-a]*(N+1))%=998244353;
    for(i=S;i>=a;i--)(v[i]+=v[i-a])%=998244353;
  }
  cout<<ans<<endl;
  return 0;
}