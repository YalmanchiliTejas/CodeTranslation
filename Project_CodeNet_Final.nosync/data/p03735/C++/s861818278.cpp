#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
multiset<pair<ll, ll>> XY;
multiset<ll> R, B;
ll Res = 1ll << 60;

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    ll x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    R.insert(x);
    B.insert(y);
    XY.insert(make_pair(x, y));
  }
  for (auto xy : XY) {
    ll x, y;
    tie(x, y) = xy;
    Res = min(Res, (*R.rbegin() - *R.begin()) * (*B.rbegin() - *B.begin()));
    R.erase(R.find(x));
    R.insert(y);
    B.erase(B.find(y));
    B.insert(x);
    assert(R.size() == N && B.size() == N);
  }
  cout << Res << endl;
  return 0;
}
