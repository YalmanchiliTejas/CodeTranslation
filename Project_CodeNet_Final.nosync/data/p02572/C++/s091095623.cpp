#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;



int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll sum = 0;
  ll height = 0;
  ll mod = 1000000007;
  for(int i=1; i<n; ++i) {
    height = (height+a[i-1])%mod;
    sum += height * a[i];
    sum %= mod;
  }
    
  cout << sum << endl;
  
  return 0;
}