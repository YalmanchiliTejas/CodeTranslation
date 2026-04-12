#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll n,k; cin>>n>>k;
  ll ans=0;
  for(ll i=1;i<=n;i++){
    if(0<(i-k)*(n/i)) ans+=(i-k)*(n/i);
    if(0<n%i-k+1) ans+=n%i-k+1;
  }
  if(k==0) ans-=n;
  cout<<ans<<endl;
}