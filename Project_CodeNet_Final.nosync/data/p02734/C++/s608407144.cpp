#include<bits/stdc++.h>
using namespace std;
int main(){
  long long i,a,N,S,ans=0;
  cin>>N>>S;
  vector<long long> v(S+1,0);
  while(N--){
    cin>>a;
    ++v[0];
    for(i=S;i>=a;i--)(v[i]+=v[i-a])%=998244353;
    ans+=v[S];
  }
  cout<<ans%998244353<<endl;
}