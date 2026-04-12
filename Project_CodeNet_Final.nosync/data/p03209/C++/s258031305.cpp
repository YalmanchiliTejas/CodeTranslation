#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()
#define sortAl(v) sort(all(v))
#define sortAlr(v)          \
  sort(v.begin(), v.end()); \
  reverse(v.begin(), v.end())

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T &a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T &a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
#define INF LLONG_MAX

ll memo[51][2];

// d次元バーガーを食す
ll eat(ll d, ll x) {
  if (x <= 0) {
    return 0;
  }
  if (x >= memo[d][0]) {
    return memo[d][1];
  } else {
    x--;
    ll ans = 0;
    if (x >= memo[d - 1][0]) {
      ans += memo[d - 1][1];
      x -= memo[d - 1][0];
    } else {
      return ans + eat(d - 1, x);
    }
    // 真ん中のパティ
    if (x > 0) {
      x--;
      ans++;
    } else {
      return ans;
    }
    return ans + eat(d - 1, x);
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n, x;
  cin >> n >> x;

  ll ans = 0;

  memo[0][0] = 1; // 全体の厚み
  memo[0][1] = 1; // パティの数

  REP(i, 51) {
    memo[i][0] = memo[i - 1][0] * 2 + 3;
    memo[i][1] = memo[i - 1][1] * 2 + 1;
  }

  cout << eat(n, x) << endl;

  return 0;
}
