#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/integer/common_factor.hpp>
#include <boost/integer/common_factor_rt.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using std::string;
using std::vector;
using std::set;
using std::multiset;
using std::unordered_set;
using std::map;
using std::multimap;
using std::unordered_map;
using std::pair;
using std::cin;
using std::cout;

using boost::multiprecision::cpp_int;
using cpp_dec_float_1000 = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1000, boost::int128_type>>;

typedef uintmax_t    ull;
typedef intmax_t     ll;
typedef uint64_t     ul;
typedef uint32_t     ui;
typedef uint8_t      uc;

constexpr char CRLF  = '\n';
constexpr char SPACE = ' ';
constexpr char VECTOR_COUT_SEPARATOR = SPACE;
constexpr ll INF = 1000'000'007;
constexpr int MOD = 1000'000'007;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> std::ostream& operator<< (std::ostream& os, const std::vector<T>& vc) { for(auto it = vc.begin(); it != vc.end(); ++it) { if (std::next(it) == vc.end()) os << *it; else os << *it << VECTOR_COUT_SEPARATOR; } return os; }
template<class T1, class T2> inline std::ostream & operator<< (std::ostream & os, const std::pair<T1, T2> & p) { return os << p.first << ' ' << p.second; }
template<class T> T modinv(T a, T m) { T b = m, u = 1, v = 0; while (b) { T t = a / b; a -= t * b; boost::swap(a, b); u -= t * v; boost::swap(u, v); } u %= m; if (u < 0) u += m; return u; }
template<class T> inline bool isSosuu(const T& n) { if (n == T(1)) { return false; } for (T i = 2; i*i <= n; ++i) { if (n % i == 0) { return false; } } return true; }
template<class T> vector<vector<T>> split (const vector<T>& S, T delim) { vector<vector<T>> ret{}; vector<T> buff{}; for (auto c : S) { if (c == delim) { if (!buff.empty()) ret.push_back(buff); buff.clear(); } else { buff.push_back(c); } } if (!buff.empty()) ret.push_back(buff); return ret; }
template<class T> inline void printYesNo(const T& t) { cout << (t ? "Yes" : "No") << CRLF; }
template<class T = int64_t> T modpow(T N, T P, T M) { T ret{1}; N %= M; while (P) { if (P & 0x01) { ret *= N; ret %= M; } P >>= 1; N *= N; N %= M; } return ret; }

/** code for assert debug begin */
int gErr = 0;
#define ASSERT(p) if(!(p)){ gErr = 1; }else{ ; }
/** code for assert debug end */

struct Tmp
{
public:
  int H, W;
  vector<vector<int>> A;
  vector<vector<int>> memo;
  Tmp(int H, int W)
  : H(H)
  , W(W)
  , A(H, vector<int>(W))
  , memo(H, vector<int>(W))
  {}

  bool operator() () {
    return rec(0, 0);
  }

  bool rec(int i, int j) {
    int ni = -1, nj = -1;
    if (!(i <= 0)) {
      if (A[i-1][j] && !memo[i-1][j]) {
        return false;
      }
    }
    if (!(j <= 0)) {
      if (A[i][j-1] && !memo[i][j-1]) {
        return false;
      }
    }
    if (i < H - 1) {
      if (A[i+1][j]) {
        ni = i + 1;
        nj = j;
      }
    }
    if (j < W - 1) {
      if (A[i][j+1]) {
        if (ni != -1 || nj != -1)
          return false;
        ni = i;
        nj = j + 1;
      }
    }
    if (ni == -1 || nj == -1) {
      return true;
    }
    memo[i][j] = 1;
    return rec(ni, nj);
  }
};

void solve(void)
{
  int H, W; cin >> H >> W;
  Tmp t(H, W);
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      char c; cin >> c;
      if (c == '#') {
        t.A[i][j] = 1;
      }
    }
  }

  auto ans = t();
  cout << (ans ? "Possible" : "Impossible") << CRLF;
  return;
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  solve();

  return 0;
}
