
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N;
ll a[60];

bool check(const ll K) {
  ll rest = K;
  ll t = N - 1 - K;
  for(ll i = 0; i < N; ++i) {
    if ((a[i] - t + N) / (N + 1) > rest) return false;
    rest -= (a[i] - t + N) / (N + 1);
  }

  return true;
}
int main () {
  cin >> N;
  for(ll i = 0; i < N; ++i) cin >> a[i];

  ll l = 0;
  ll r = LLONG_MAX;
  ll ret = r;
  while(l <= r) {
    ll mid = l + (r - l) / 2;

    bool has = false;
    for(ll i = -N; i <= N && mid + i <= r; ++i) {
      if (mid + i < l) continue;
      if (check(mid + i)) {
        ret = min(ret, mid + i);
        r = min(r, mid + i - 1);
        has = true;
        break;
      }
    }

    if (!has) {
      l = mid + N + 1;
    }
  }
  cout << ret << endl;
}