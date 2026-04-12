#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
  ll mod=1000000007;
  int n;
  cin>>n;
  vector<ll>a(n);
  rep(i,n) cin>>a[i];
  ll sum=0;
  rep(i,n) {
    sum+=a[i];
  }
  ll ans=0;
  rep(i,n){
    sum-=a[i];
    ll x=sum;
    x%=mod;
    x*=a[i];
    x%=mod;
    ans+=x;
    ans%=mod;
  }
  cout<<ans<<endl;
}