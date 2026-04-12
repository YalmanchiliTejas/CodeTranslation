#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll N, X, M;
  cin >> N >> X >> M;
  if (X == 0) {
    cout << X << endl;
    return 0;
  }

  vector<ll> S(M + 1, 0);
  vector<ll> T(M + 1, 0);
  S.at(X) = 1;
  T.at(1) = X;

  ll i = 2;

  bool loop = false;
  ll l, r;
  while (i <= N) {
    X = (X * X) % M;
    T.at(i) = T.at(i - 1) + X;
    if (S.at(X) > 0) {
      l = S.at(X) - 1;
      r = i - 1;
      loop = true;
      break;
    } else {
      S.at(X) = i;
    }
    i++;
  }
  ll ans = T.at(i - 1);

  if (loop) {
    ll dx = r - l;
    ll dy = T.at(r) - T.at(l);
    ans += dy * ((N - r) / dx);
    ans += T.at(l + (N - r) % dx) - T.at(l);
  }

  cout << ans << endl;
}
