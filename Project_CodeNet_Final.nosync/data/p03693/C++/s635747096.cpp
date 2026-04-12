#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <set>
#include <queue>
#include <assert.h>
#include <cmath>
#include <map>


using std::cerr;
using std::cin;
using std::cout;
using std::pair;
using std::string;
using std::vector;
//region
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORR(i, a, b) for (int i = (b); i >= (b); --i)
#define rep(i, n) for (unsigned i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n)-1; i >= 0; --i)
#define repr1(i, n) for (int i = (n); i > 0; --i)
#define all(vec) (vec).begin(), (vec).end()
#define sz(x) (int((x).size()))
#define mset(v, n) std::memset((v), n, sizeof(v))
#define BIT(N) (1LL << (N))
#define each(i, v) for (auto&& i : (v))
#define unless(f) if(!(f))
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using vint = vector<int>;
using vlong = vector<ll>;
using vstr = vector<string>;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpll = vector<pll>;
using vvi = vector<vint>;
using vvl = vector<vlong>;
vector<string> split(const string &s, const string &delim) {
  vector<string> res;
  uint pos = 0;
  while (true) {
    const size_t found = s.find(delim, pos);
    if (found < 0) {
      res.push_back(s.substr(pos));
      break;
    }
    res.push_back(s.substr(pos, found - pos));
    pos = found + delim.size();
  }
  return res;
}
template<typename T> string join(vector<T> &vec, const string &sep) {
  size_t size = vec.size();
  if (!size) return "";
  std::stringstream ss;
  for (int i = 0; i < size - 1; i++)
    ss << vec[i] << sep;
  ss << vec[size - 1];
  return ss.str();
}
template<typename T> std::istream &operator>>(std::istream &is, vector<T> &vec) { for (T &x : vec) is >> x; return is; }
template<typename Iter> inline void print(const Iter &first, const Iter &last, const std::string &d, bool endline) {
  cout << *first;
  for (Iter iter = first + 1; iter < last; ++iter) {
    cout << d << *iter;
  }
  if (endline) cout << "\n";
}
constexpr ll powmod(ll a, ull b, uint p) {
  ll res = 1;
  while (b > 0) {
    if (b % 2) res = res * a % p;
    a = a * a % p;
    b >>= 1u;
  }
  return res;
}
template<class T> bool chmax(T &a, const T &b) { return a < b ? (a = b, true) : false; }
template<class T> bool chmin(T &a, const T &b) { return a > b ? (a = b, true) : false; }
template <typename T> void bsort(vector<T>& v) { std::sort(v.begin(), v.end()); }
template <typename T> void rsort(vector<T>& v) { std::sort(v.begin(), v.end(), std::greater<T>()); }
struct iii {
    iii() {
      cin.tie(nullptr); cout.tie(nullptr);
      std::ios::sync_with_stdio(false);
      cout << std::fixed << std::setprecision(16);
    }
} init;
//endregion

void solve();

int main() {
  int t = 1;
  // scanf("%d", &t);
  // cin >> t;
  rep(i, t) solve();
  return 0;
}

int check(vint a, vint b) {
  int sum = 0;
  rep(i,a.size()) {
    sum += (b[i]-a[i])*(b[i]-a[i]);
  }

  for(int i = 1; i * i <= sum; ++i) {
    if(i*i==sum) return true;
  }
  return false;
}

void solve(){
  int r, g, b;
  cin >> r >> g >> b;
  puts((r * 100 + g * 10 + b) % 4 ? "NO" : "YES");

}
