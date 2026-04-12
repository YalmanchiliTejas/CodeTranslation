#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;



int main() {
  ll n;
  cin >>n;
  ll a[n];
  rep(i,n)cin >> a[i];
  ll ans=0;

  ll sum[n];
  for(int i=n-1;i>=0;i--){
    if(i==n-1){sum[i]=a[i];}else{sum[i]=(sum[i+1]+a[i])%mod;}
  }
  rep(i,n-1){
    ll g=(a[i]*sum[i+1])%mod;
    ans=(ans+g)%mod;
  }
  cout << ans << endl;
}
