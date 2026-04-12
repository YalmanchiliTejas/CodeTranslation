#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  ll N;
  ll mod = 1000000007;
  cin >> N;
  vector<ll> A(N, 0);
  vector<ll> B(N + 1, 0);
  for (ll i = 0; i < N; i++) {
    cin >> A.at(i);
    B.at(i + 1) = B.at(i) + A.at(i);
  }
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ll sum = (B.at(N) - B.at(i + 1)) % mod;
    ans += A.at(i) * sum; 
    ans %= mod;
  }
  cout << ans << endl;
}