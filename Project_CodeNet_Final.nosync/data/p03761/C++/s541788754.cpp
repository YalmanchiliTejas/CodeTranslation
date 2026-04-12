#include "bits/stdc++.h"
//region region
using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::pair;
using std::queue;
using std::priority_queue;
using std::swap;
//endregion
//region define/typedef
#pragma warning(disable:4996)
//auto
#define var auto
#define cvar const auto&
//a..b-1
#define FOR(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
//b..a
#define FORR(i, a, b) for(int (i) = (b); (i) >= (b); (i)--)
//0..n-1
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
//1..n
#define rep1(i, n) for(int (i) = 1; (i) <= (n); (i)++)
//n-1..0
#define repr(i, n) for(int (i) = (n) - 1; (i) >= 0; (i)--)
//n-1..1
#define repr1(i, n) for(int (i) = (n); (i) > 0; (i)--)
#define in1(a) cin >> a
#define in2(a, b) cin >> a >> b
#define in3(a, b, c) cin >> a >> b >> c
#define in4(a, b, c, d) cin >> a >> b >> c >> d
#define in5(a, b, c, d, e) cin >> a >> b >> c >> d >> e
#define pb push_back
#define mp std::make_pair
#define mt std::make_tuple
#define endl "\n"
#define outif(b, t, f) cout << ((b) ? (t) : (f)) << endl
#define bsort(vec) std::sort((vec).begin(), (vec).end())
#define rsort(vec) std::sort((vec).rbegin(), (vec).rend())
#define all(vec) (vec).begin(), (vec).end()
#define even(i) (!(i&1))
#define odd(i) (i&1)
#define sz(x) (int((x).size()))
#define mset(v, n) std::memset((v), n, sizeof(v))
#define setminus(v) mset(v, -1)
#define setzero(v) mset(v, 0)
#define BIT(N) (1LL<<(N))
using ll = long long;
using lld = long double;
using uint = unsigned int;
using vint = vector<int>;
using vlong = vector<ll>;
using vstr = vector<string>;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpll = vector<pll>;
const int MAX = 2147483647;
const int MIN = 0 - 2147483648;
const ll MAXL = 922337203685775807;
const ll MINL = 0 - 922337203685775808;
//endregion
//region methods/operator
#pragma warning (disable:6031)

ll parse(const string &num) {
  std::stringstream ss;
  ss << num << std::flush;
  ll n;
  ss >> n;
  return n;
}

string to_string(const ll n) {
  std::stringstream ss;
  ss << n << std::flush;
  return ss.str();
}

vector<string> split(const string &s, const string &delim) {
  vector<string> res;
  auto pos = 0;
  while (true) {
    const int found = s.find(delim, pos);
    if (found >= 0) {
      res.push_back(s.substr(pos, found - pos));
    } else {
      res.push_back(s.substr(pos));
      break;
    }
    pos = found + delim.size();
  }
  return res;
}

template<typename T>
string join(vector<T> &vec, const string &sep = " ") {
  var size = vec.size();
  if (size == 0) return "";
  std::stringstream ss;
  for (int i = 0; i < size - 1; i++) {
    ss << vec[i] << sep;
  }
  ss << vec[size - 1];
  return ss.str();
}

template<typename T>
std::istream &operator>>(std::istream &is, vector<T> &vec) {
  for (T &x : vec) is >> x;
  return is;
}

template<typename T>
void print(T t) {
  cout << t << endl << std::flush;
}

ll powmod(ll a, ll b, ll p) {
  ll res = 1;
  while (b > 0) {
    if (b % 2) res = res * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return res;
}

ll gcd(ll a, ll b) {
  if (a < b) gcd(b, a);
  ll r;
  while ((r = a % b)) {
    a = b;
    b = r;
  }
  return b;
}

ll lcm(const ll a, const ll b) { return a / gcd(a, b) * b; }

template<class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

//endregion
//region initialize

struct iii {
    iii() {
      cin.tie(nullptr);
      std::ios::sync_with_stdio(false);
      cout << std::fixed << std::setprecision(16);
    }
} init;

//endregion

int main() {
  int n; cin >> n;

  vector<vector<int>> cnt(26, vector<int>(n));
  rep(i, n) {
    string s; cin >> s;
    for (char c : s) {
      cnt[c - 'a'][i]++;
    }
  }
  rep(i, 26) {
    rep(_, *std::min_element(all(cnt[i]))) {
      putchar(i + 'a');
    }
  }
  putchar('\n');
}
