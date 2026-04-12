#include<bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (ll i = static_cast<int>(a); i < static_cast<int>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
#define chmax(x, a)  do { x = max(x, a); } while(0)
#define chmin(x, a)  do { x = min(x, a); } while(0)

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll,ll> PLL;

ll N, ans;
vector<ll> v;
ll dp[3000][3000];
const ll WILD_CARD = 2500;
const ll SENTINEL = 2600;

struct T {
  ll x, y, val;
  T(ll x, ll y, ll val): x(x), y(y), val(val) {}
};

void update(ll x, ll y, ll val) {
  chmax(dp[x][y], val);
  chmax(dp[y][x], val);
  chmax(dp[x][WILD_CARD], val);
  chmax(dp[y][WILD_CARD], val);
  chmax(dp[WILD_CARD][x], val);
  chmax(dp[WILD_CARD][y], val);
  chmax(dp[WILD_CARD][WILD_CARD], val);
}

void solve() {
  cin >> N;
  v.resize(3*N);
  rep(i, 3*N)
    cin >> v[i], v[i]--;
  v.push_back(SENTINEL + 1);
  v.push_back(SENTINEL + 2);
  rep(i, 3000) rep(j, 3000) dp[i][j] = -(1e18);
  update(v[0], v[1], 0);

  for (ll i = 2; i < 3 * N; i+=3) {
    vector<T> upd;
    // A
    if (v[i] == v[i+1] && v[i+1] == v[i+2]) {
      ans++;
      continue;
    }
    vector<ll> w = {v[i], v[i+1], v[i+2]};
    sort(begin(w),end(w));
    do {
      ll a = w[0], b = w[1], c = w[2];
      // printf("a = %lld b = %lld c = %lld\n", a, b, c);
      // B
      if (a == b) {
        rep(y, N) {
          upd.emplace_back(c, y, dp[a][y]+1);
        }
      }
      // C
      upd.emplace_back(b, c, dp[a][a]+1);
      // D
      ;
      // E
      rep(x, N)
        upd.emplace_back(x, a, dp[x][WILD_CARD]);
      // F
      upd.emplace_back(a, b, dp[WILD_CARD][WILD_CARD]);
    } while (next_permutation(begin(w), end(w)));

    for (auto [x, y, val] : upd) {
      update(x, y, val);
    }
  }

  ans += dp[WILD_CARD][WILD_CARD];
  cout << ans << endl;
}

int main() {
  //ll T;
  //cin >> T;
  //rep(_,T)
    solve();
  return 0;
}
