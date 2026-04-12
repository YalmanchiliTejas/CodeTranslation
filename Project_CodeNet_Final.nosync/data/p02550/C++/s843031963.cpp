#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  ll N, X, M;
  cin >> N >> X >> M;
  vector<ll> v, vloop;
  set<ll> s;
  s.insert(X);
  v.push_back(X);
  ll ans = X;
  ll nrest = N - 1;
  for (int i = 1; i < N; i++) {
    ll a = v[i - 1] * v[i - 1] % M;
    if (s.count(a) == 0) {
      s.insert(a);
      v.push_back(a);
      ans += a;
      nrest--;
    } else {
      for (int j = 0; j < i; j++) {
        if (v[j] == a) {
          vloop.resize(i - j);

          copy(v.begin() + j, v.begin() + i, vloop.begin());
          break;
        }
      }
      break;
    }
  }
  ll sum = 0;
  for (ll i : vloop) {
    sum += i;
  }

  if (nrest != 0) {
    ans += sum * (nrest / vloop.size());
    nrest %= vloop.size();

    for (int i = 0; i < nrest; i++) {
      ans += vloop[i];
    }
  }
  cout << ans << endl;
}
