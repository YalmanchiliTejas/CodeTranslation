#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

int main() {
ll N,M;
  cin>>N>>M;
  
vector<vector<ll>> vec(N,vector<ll>(0));
  for(ll i=0;i<M;i++) {
ll a,b;
    cin>>a>>b;
    vec[a-1].push_back(b);
    vec[b-1].push_back(a);
  }
  
  vector<ll> A(N);
  for(ll i=0;i<N;i++) {
A[i]=i+1;
  }
  
  
  sort(all(A));
  ll ans=0;
  do {
    if(A[0]!=1) {
break;
    }
    
    bool b=true;
    for(ll i=0;i<N-1;i++) {
ll k=A[i];
      ll n=A[i+1];
      bool a=false;
      for(auto x:vec[k-1]) {
if(x==n) {
a=true;
}
      }
      if(!a) {
b=false;
        break;
      }
    }
    
    
    if(b) {
ans++;
    }
  }
  
    while(next_permutation(all(A)));
    
    cout<<ans<<endl;
  }
      
      
        
        
        
        
        