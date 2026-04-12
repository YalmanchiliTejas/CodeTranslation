#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
vector<vector<ll>> note;
vector<ll> vec;

ll dp(ll i,ll j,ll sum) {
  if(i==j) {
return vec[i-1];
  }
  if(i+1==j) {
return max(vec[i-1],vec[j-1]);
  }
  
  if(note[i-1][j-1]>0) {
return note[i-1][j-1];
  }
  
  
    ll s=max(sum-dp(i+1,j,sum-vec[i-1]),sum-dp(i,j-1,sum-vec[j-1]));
  note[i-1][j-1]=s;
  return s;
    
}

int main() {
  ll N;
  cin>>N;
  note=vector<vector<ll>> (N,vector<ll>(N,0));
  vec=vector<ll> (N);
  ll sum=0;

  for(ll i=0;i<N;i++) {
cin>>vec[i];
    sum+=vec[i];
  }
  
  ll X=dp(1,N,sum);
  cout<<X-sum+X<<endl;
}
  
  
  
 
  
