#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  ll S; cin >> S;
  vector<ll> A(N); for (ll i = 0; i < N; i++) cin >> A[i];

  ll MOD = 998244353;
  vector<vector<ll>> coef(N + 1, vector<ll>(S + 1, 0));
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    coef[i][0]++;
    for (ll j = 0; j <= S; j++) {
      coef[i + 1][j] += coef[i][j];
      if (j + A[i] <= S) {
        coef[i + 1][j + A[i]] += coef[i][j];
      }
      coef[i + 1][j] %= MOD;
    }
    ans = (ans + coef[i + 1][S]) % MOD;
  }
  cout << ans << '\n';
  return 0;
}