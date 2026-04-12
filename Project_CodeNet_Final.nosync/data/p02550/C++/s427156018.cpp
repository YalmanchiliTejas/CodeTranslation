#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define pb push_back
#define COUT(x) cout << (x) << "\n"
#define COUTF(x) cout << setprecision(15) << (x) << "\n"
#define ENDL cout << "\n"
#define DF(x) x.erase(x.begin())
#define ALL(x) x.begin(), x.end()
#define SORT(x) sort(ALL(x))
#define RSORT(x) sort(x.rbegin(), x.rend())
#define REVERSE(x) reverse(ALL(x))
#define MAX(x) *max_element(ALL(x))
#define MAXI(x) max_element(ALL(x)) - x.begin()
#define SUM(x) accumulate(ALL(x), 0ll)
#define COUNT(x, y) count(ALL(x), y);
#define ANS cout << ans << "\n"
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define Yes cout << "Yes\n";
#define No cout << "No\n";
#define YN YES else NO
#define yn Yes else No
#define init() \
  cin.tie(0);  \
  ios::sync_with_stdio(false)
#define LINE cerr << "[debug] line: " << __LINE__ << "\n";
#define debug(x) cerr << "[debug] " << #x << ": " << x << "\n";
#define debugV(v)                       \
  cerr << "[debugV] " << #v << ":";     \
  rep(z, v.size()) cerr << " " << v[z]; \
  cerr << "\n";
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using mll = map<ll, ll>;
using qll = queue<ll>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vs = vector<string>;

template <typename T>
inline istream& operator>>(istream& i, vector<T>& v) {
  rep(j, v.size()) i >> v[j];
  return i;
}

template <typename T1, typename T2>
inline istream& operator>>(istream& i, pair<T1, T2>& v) {
  return i >> v.first >> v.second;
}

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ld PI = 3.141592653589793238462643383279;
ll get_digit(ll x) {
  return to_string(x).size();
}

ll gcd(ll x, ll y) {
  return y ? gcd(y, x % y) : x;
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

signed main() {
  init();
  ll N, X, M;
  cin >> N >> X >> M;
  ll a = X;
  mll m;
  m[a]++;
  bool roop = false;
  ll roop_num = -1;
  ll t = 0;
  ll count = 0;
  ll ans = 0;
  ll nokori_s = 0;
  rep(i, N) {
    if (i == 0) {
      ans += a;
      continue;
    }
    a = (a * a % M);

    if (roop) {
      if (a == roop_num) {
        // debug("検出");
        ll nokori = N - (nokori_s + 1) + 1;
        // debug(nokori);
        // debug(count);
        ans += nokori / count * t;
        // debug(nokori % count);
        rep(j, nokori % count) {
          if (j == 0) {
            ans += roop_num;
            a = roop_num;
            continue;
          }
          a = (a * a % M);
          ans += a;
        }
        COUT(ans);
        return 0;
      }
      t += a;
      count++;
      continue;
    }

    if (roop == false and m[a] != 0) {
      roop = true;
      roop_num = a;
      count = 1;
      nokori_s = i;
      // debug("aaa");
      // debug(roop_num);
      t = a;
      continue;
    }
    m[a]++;
    ans += a;
  }
  ANS;
  return 0;
}