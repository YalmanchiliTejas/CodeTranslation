#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

typedef long long ll;

void solve() {
  ll N, X, M;
  cin >> N >> X >> M;

  map<ll, pair<ll, ll>> seen;
  ll ans = 0;
  ll turn = 0;
  while (N) {
    if (seen.count(X)) {
      ll dist = turn - seen[X].first;
      ll times = N / dist;
      N %= dist;
      ans += (ans - seen[X].second) * times;
    }
    if (N) {
      seen[X] = {turn++, ans};
      ans += X;
      X = X * X % M;
      N--;
    }
  }

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // int t;
  // cin >> t;
  // while (t--) {
  solve();
  cout << nl;
  // }

  return 0;
}