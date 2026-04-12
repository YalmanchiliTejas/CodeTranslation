#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i,n){
    ll x;
    cin >> x;
    a[i] = x % 1000000007;
  }
  b[0] = a[0];
  rep(i,n-1){
    
      b[i+1] = (b[i] + a[i+1]) % 1000000007;
    
  }
  
  rep(i,n-1){
    ans = (ans + (a[n-1-i] * b[n-2-i]) % 1000000007) % 1000000007;
  }
  
  cout << ans;
  return 0;
}




