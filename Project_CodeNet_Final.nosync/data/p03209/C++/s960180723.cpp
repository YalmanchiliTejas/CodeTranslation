#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;

ll INF = (1ll << 32);
double EPS = 1e-4;

ll MOD = 1000000007;

namespace std {
  template <>
  class hash<pii> {
  public:
    size_t operator()(const pii& x) const {
      return hash<ll>()(x.first) ^ hash<ll>()(x.second);
    }
  };
}

unordered_map<pii, ll> cache;

ll f(ll a, ll b) {
  if (b == 0) return 0;
  if (a == 0) return 1;

  if (cache.find(make_pair(a, b)) != cache.end()) {
    return cache[make_pair(a, b)];
  }

  ll h = 1;
  for (ll i = 0; i < a; i++) {
    h = h * 2 + 3;
  }

  ll prev_h = (h - 3) / 2;

  ll ret = 0;

  if (b >= 2) ret += f(a - 1, min(prev_h, b - 1));
  if (b >= 2 + prev_h) ret += 1;
  if (b >= 3 + prev_h) ret += f(a - 1, min(prev_h, b - 2 - prev_h));

  cache[make_pair(a, b)] = ret;

  return ret;
}

int main() {
  ll N, X;
  cin >> N >> X;

  cout << f(N, X) << endl;
}