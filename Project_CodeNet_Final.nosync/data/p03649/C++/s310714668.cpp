#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  vector<ll> A(N); for (ll i = 0; i < N; i++) cin >> A[i];

  ll ans = 0;
  while (true) {
    vector<ll> cnt(N, 0);
    ll sum = 0;
    for (ll i = 0; i < N; i++) {
      cnt[i] = A[i] / N;
      sum += cnt[i];
    }
    ans += sum;
    if (sum == 0) break;
    for (ll i = 0; i < N; i++) {
      A[i] = A[i] - N * cnt[i] + (sum - cnt[i]);
    }
  }

  cout << ans << '\n';

  return 0;
}