#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
using ll=long long;
int main(){
  ll n;
  cin>>n;
  vector<ll> a(n);
  vector<ll> b(n+1,0);
  for(int i=0;i<n;i++){
    cin>>a[i];
    b[i+1]=b[i]+a[i];
  }
  ll ans=0;
  for(int i=0;i<n;i++){
    ll s=(b[n]-b[i+1])%mod;
    ans+=s*a[i];
    ans=ans%mod;
  }
  cout<<ans<<endl;
  return 0;
}