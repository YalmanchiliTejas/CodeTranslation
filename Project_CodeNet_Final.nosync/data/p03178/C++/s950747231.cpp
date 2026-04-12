#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string K; cin >> K;
  ll D; cin >> D;
  ll N = K.size();

  ll MOD = 1e9 + 7;
  vector<ll> eq(D, 0), ls(D, 0);
  eq[0] = 1;
  for (ll i = 0; i < N; i++) {
    int d = K[i] - '0';
    vector<ll> eq2(D, 0), ls2(D, 0);

    for (ll j = 0; j < D; j++) {
      eq2[(j + d) % D] += eq[j];

      for (ll k = 0; k < d; k++) {
        ls2[(j + k) % D] += eq[j];
      }

      for (ll k = 0; k < 10; k++) {
        ls2[(j + k) % D] += ls[j];
      }
    }
    for (ll j = 0; j < D; j++) {
      eq[j] = eq2[j] % MOD;
      ls[j] = ls2[j] % MOD;
      // cout << eq[j] << ' ' << ls[j] << '\n';
    }
    // cout << '\n';
  }
  cout << (eq[0] + ls[0] - 1 + MOD) % MOD << '\n';
  return 0;
}