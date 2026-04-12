#include <bits/stdc++.h>
#include <vector>
#include <iostream>

#define rep(i,n) for (int i=0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int mod=1'000'000'007;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);

  rep(i,n) cin >> a[i];
  ll ans = 0;
  ll sum = 0;
  rep(i,n) {
    ans = (ans + a[i] * sum) % mod;
    sum = (sum+ a[i]) % mod;  
  }
  cout << ans << endl;
  return 0;

}
