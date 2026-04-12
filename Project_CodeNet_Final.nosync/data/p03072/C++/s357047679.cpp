#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll N; cin >> N;
  vector<ll> H(N);
  for (ll j=0; j < N; ++j) cin >> H[j];
  ll mm = H[0];
  ll ans = 0;
  for (ll j=0; j < N; ++j) {
    if (H[j] >= mm) {
      ans += 1;
    }
    mm = max(mm, H[j]);
  }
  cout << ans << endl;
  return 0;
}
