#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define pb push_back
#define COUT(x) cout << (x) << endl
#define COUTF(x) cout << setprecision(15) << (x) << endl
#define ENDL cout << endl
#define DF(x) x.erase(x.begin())  // 先頭文字削除
#define ALL(x) x.begin(), x.end()
#define SORT(x) sort(ALL(x))
#define REVERSE(x) reverse(ALL(x))
#ifdef _DEBUG
#define debug(x) cout << "[debug] " << #x << ": " << x << endl
#else
#define debug(x)
#endif
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using P = pair<ll, ll>;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr double PI = 3.141592653589793238462643383279;
ll getDigit(ll x) {
  return x == 0 ? 1 : log10(x) + 1;
}

ll gcd(ll x, ll y) {
  return y ? gcd(y, x % y) : x;
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

vector<P> factorize(ll n) {
  vector<P> result;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      result.pb({i, 0});
      while (n % i == 0) {
        n /= i;
        result.back().second++;
      }
    }
  }
  if (n != 1) {
    result.pb({n, 1});
  }
  return result;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
void debugV(const vector<T> v) {
#ifdef _DEBUG
  rep(i, v.size()) {
    cout << i << ":" << v[i] << " ";
  }
  cout << endl;
#else
  (void)v;
#endif
}

vll a(100), p(100);

ll burger(ll n, ll x) {
  if (n == 0) {
    return x <= 0 ? 0 : 1;
  }

  if (x == 1) {
    return 0;
  }
  if (1 < x && x < 2 + a[n - 1]) {
    return burger(n - 1, x - 1);
  }
  if (x == 2 + a[n - 1]) {
    return p[n - 1] + 1;
  }
  if (2 + a[n - 1] < x && x < a[n]) {
    return p[n - 1] + 1 + burger(n - 1, x - a[n - 1] - 2);
  }
  if (x == a[n]) {
    return p[n];
  }
  return 0;
}

signed main() {
  ll N, X;
  cin >> N >> X;

  rep(i, 100) {
    if (i == 0) {
      a[i] = 1;
      p[i] = 1;
      continue;
    }
    a[i] = 2 * a[i - 1] + 3;
    p[i] = 2 * p[i - 1] + 1;
  }

  ll b = burger(N, X);
  COUT(b);
  return 0;
}