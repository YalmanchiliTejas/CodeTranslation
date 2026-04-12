#include <bits/stdc++.h>
using namespace std;
using ll = long long;

main() {
  int N; cin >> N;
  vector<ll> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  ll ans = 0;
  while (1) {
    ll sum = 0;
    for (int i = 0; i < N; i++) sum += a[i] / N;
    if (sum > (N - 1) * N) {
      for (int i = 0; i < N; i++) {
        ll q = a[i] / N;
        a[i] += -q * N + (sum - q);
        ans += q;
      }
    } else {
      sort(a.begin(), a.end(), greater<int>());
      if (a[0] < N) break;
      ll q = a[0] / N;
      for (int i = 0; i < N; i++) {
        a[i] += (i == 0) ? -q * N : q;
      }
      ans += q;
    }
  }
  cout << ans << endl;
}