#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll n;
  cin >> n;
  vector<ll> A(n);
  vector<ll> P(n+1);
  for (auto& _a : A) cin >> _a;
  for (int i = 0; i < n; ++i) {
    P[i+1] = P[i] + A[i];
    P[i+1] %= mod;
  }
  
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += (A[i]*((P[n] - P[i+1]+mod)%mod)) % mod;
    ans %= mod;
  }
  ans %= mod;
  cout << ans << endl;

}
