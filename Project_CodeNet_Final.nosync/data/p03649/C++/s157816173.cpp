#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int N; cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  auto isGood = [&] (ll K) -> bool {
    ll tot = 0;
    for (int i = 0; i < N; i++) {
      tot += (1 + A[i] + K) / (N+1);
    }
    return tot <= K;
  };
  ll ans = 50.1e16;
  for (int m = 0; m <= N; m++) {
    ll mi = -1, ma = 1.1e16;
    while (ma - mi > 1) {
      ll md = (mi + ma) / 2;
      if (isGood(md * (N+1) + m)) ma = md;
      else mi = md;
    }
    ans = min(ans, ma * (N+1) + m);
  }
  cout << ans << '\n';
}