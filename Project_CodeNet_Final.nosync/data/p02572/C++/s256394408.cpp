#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n; cin >> n;
  
  vector<ll> nums(n);
  vector<ll> sums(n);
  for(int i = 0; i < n; i++) {
    ll temp; cin >> temp;
    nums.at(i) = temp;
    if(i == 0) {
      sums.at(i) = temp;
    } else {
      sums.at(i) = sums.at(i-1) + temp;
    }
  }
  ll ans = 0;
  ll mod = 1000000007;
  for(int i = n-1; i > 0; i--) {
    ll a = nums.at(i);
    ll b = sums.at(i-1) % mod;
    ans += a * b % mod;
    ans %= mod;
  }
  cout << ans << endl;
  
  return 0;
}