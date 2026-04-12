#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  vector<ll> A(N); for (ll i = 0; i < N; i++) cin >> A[i];

  ll s = 0, s2 = 0;
  ll MOD = 1e9 + 7;
  ll mod2 = 5e8 + 4;
  for (ll i = 0; i < N; i++) {
    s += A[i];
    s2 += (A[i] * A[i] % MOD);
    s %= MOD;
    s2 %= MOD;
  }

  ll ans = s * s % MOD;
  ans -= s2;
  ans = (ans + MOD) % MOD;
  ans = (ans * mod2) % MOD;
  cout << ans << '\n';
  return 0;
}