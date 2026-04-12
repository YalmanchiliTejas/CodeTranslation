#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll INF=1000000007;
  ll N;
  cin>>N;
  vector<ll> A(N);
  ll sum=0;
  ll ans=0;
  for(ll i=0;i<N;i++) {
cin>>A[i];
    sum+=A[i];
  }
  for(ll i=0;i<N-1;i++) {
    sum-=A[i];
    ans+=A[i]*(sum%INF);
    ans%=INF;
  }
  
  cout<<ans<<endl;
}

    
    
    
    