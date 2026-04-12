//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
template <typename T> using V = vector<T>;
template <typename T> using VV = vector<vector<T>>;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, a, n) for(ll i = a; i < (ll)(n); ++i)
#define repr(i, a, n) for(ll i = n - 1; (ll)a <= i; --i)
#define ENDL '\n'
typedef pair<int, int> Pi;
typedef pair<ll, ll> PL;
constexpr ll mod = 1000000007;  // 998244353;
constexpr ll INF = 1000000099;
constexpr ll LINF = (ll)(1e18 + 99);
const ld PI = acos((ld)-1);
const vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
template <typename T, typename U> inline bool chmin(T& t, const U& u) {
  if(t > u) {
    t = u;
    return 1;
  }
  return 0;
}
template <typename T, typename U> inline bool chmax(T& t, const U& u) {
  if(t < u) {
    t = u;
    return 1;
  }
  return 0;
}
template <typename T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

template <typename T, typename Y> inline T mpow(T a, Y n) {
  T res = 1;
  for(; n; n >>= 1) {
    if(n & 1) res = res * a;
    a = a * a;
  }
  return res;
}

template <typename T, typename Y>
ostream& operator<<(ostream& os, const pair<T, Y>& p) {
  return os << "{" << p.fs << "," << p.sc << "}";
}
template <typename T> ostream& operator<<(ostream& os, const V<T>& v) {
  os << "{";
  for(auto e : v) os << e << ",";
  return os << "}";
}
template <typename... Args> void debug(Args&... args) {
  for(auto const& x : {args...}) { cerr << x << ' '; }
  cerr << ENDL;
}

ll dp[2010][2010] = {};

signed main() {
  cin.tie(0);
  cerr.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  V<ll> v(3 * n);
  rep(i, 0, 3 * n) cin >> v[i];

  rep(i, 1, n + 1) rep(j, 1, n + 1) dp[i][j] = -INF;
  dp[v[0]][v[1]] = dp[v[1]][v[0]] = 0;

  ll add = 0, almx = 0;
  V<ll> rmx(n + 2, -INF);
  rmx[v[0]] = rmx[v[1]] = 0;

  rep(i, 2, 3 * n) {
    if(i == 3 * n - 1) {
      chmax(almx, ++dp[v.back()][v.back()]);
      break;
    }

    sort(v.begin() + i, v.begin() + i + 3);

    if(v[i] == v[i + 2]) {  // 0/2 + 3/3
      ++add;
      i += 2;
      continue;
    }

    V<tuple<ll, ll, ll>> upd(0);
    V<ll> per = {v[i], v[i + 1], v[i + 2]};
    sort(all(per));
    do {
      ll a = per[0], b = per[1], c = per[2];
      upd.eb(a, b, dp[c][c] + 1);  // 2/2 + 1/3
      upd.eb(a, b, almx);          // 2/2 + 1/3

      rep(j, 1, n + 1) upd.eb(a, j, rmx[j]);  // 1/2 + 2/3
      rep(j, 1, n + 1) upd.eb(j, a, rmx[j]);  // 1/2 + 2/3

      if(a == b) {
        rep(j, 1, n + 1) {
          upd.eb(c, j, dp[a][j] + 1);  // 1/2 + 2/3
          upd.eb(j, c, dp[a][j] + 1);  // 1/2 + 2/3
          upd.eb(c, j, dp[j][a] + 1);  // 1/2 + 2/3
          upd.eb(j, c, dp[j][a] + 1);  // 1/2 + 2/3
        }
      }

    } while(next_permutation(all(per)));

    rep(j, 0, siz(upd)) {
      ll a, b, c;
      tie(a, b, c) = upd[j];
      chmax(dp[a][b], c);
      chmax(almx, c);
      chmax(rmx[a], c);
    }
    i += 2;
  }

  cout << add + almx << ENDL;
}
//! ( . _ . ) !
// CHECK overflow,vector_size,what to output?