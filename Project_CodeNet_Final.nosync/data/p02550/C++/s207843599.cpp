#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  ll X; cin >> X;
  ll M; cin >> M;

  if (N < 1e7) {
    ll x = X;
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
      ans += x;
      x = (x * x) % M;
    }
    cout << ans << '\n';
    return 0;
  }


  vector<ll> A(2 * M + X, 0);
  vector<ll> ind(2 * M + X, -1);

  ll x = X;
  ll is, ie;

  A[0] = X;
  ind[X] = 0;
  for (ll i = 1; i < N; i++) {
    x = (x * x) % M;
    if (ind[x] >= 0) {
      A[i] = x;
      is = ind[x];
      ie = i;
      break;
    } else {
      A[i] = x;
      ind[x] = i;
    }
  }

  ll sum_start = 0, sum_set = 0;
  for (ll i = 0; i <= is; i++) {
    sum_start += A[i];
  }
  for (ll i = is + 1; i <= ie; i++) {
    sum_set += A[i];
  }

  ll m = (N - (is + 1)) / (ie - is);

  ll ans = 0;
  ans += sum_start;
  ans += sum_set * m;
  for (ll i = 0; i < N; i++) {
    ll index = i + is + (ie - is) * m + 1;
    if (index >= N) break;
    ans += A[i + is + 1];
  }
  cout << ans << '\n';
  return 0;
}