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
using cpp_dec_float_1000 = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1000>>;

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

template<class T>
struct Tmp
{
public:
  Tmp(int N, int K);
  int N, K;
  vector<char> S;
  vector<vector<T>> dpF, dpG;
  T recF(int i, int k);
  T recG(int i, int k);
};

template<class T>
Tmp<T>::Tmp(int N, int K)
  : N(N)
  , K(K)
  , S(N)
  , dpF(N, vector<T>(K+1, T(-1)))
  , dpG(N, vector<T>(K+1, T(-1)))
{}

template<class T>
T Tmp<T>::recF(int i, int k)
{
  int Si = S[i] - '0';
  if (dpF[i][k] != -1) {
    return dpF[i][k];
  }
  if (k == 0) {
    return dpF[i][0] = 1;
  }
  if (i == (N - 1)) {
    if (k == 0) {
      /** 到達しないはず */
      return dpF[i][k] = 1;
    }
    else if (k == 1) {
      return dpF[i][k] = Si;
    }
    else {
      return dpF[i][k] = 0;
    }
  }

  T res{};
  if (Si != 0) {
    res += recF(i+1, k-1);
    res += recG(i+1, k);
  }
  else {
    res += recF(i+1, k);
  }
  if (Si > 1) {
    res += recG(i+1, k-1) * (Si - 1);
  }
  return dpF[i][k] = res;
}

template<class T>
T Tmp<T>::recG(int i, int k)
{
  if (dpG[i][k] != -1) {
    return dpG[i][k];
  }
  if (k == 0) {
    return dpG[i][0] = 1;
  }
  if (i == (N - 1)) {
    if (k == 0) {
      /** 到達しないはず */
      return dpG[i][k] = 1;
    }
    else if (k == 1) {
      return dpG[i][k] = 9;
    }
    else {
      return dpG[i][k] = 0;
    }
  }
  T res{};
  res += recG(i+1, k-1) * 9;
  res += recG(i+1, k);
  return dpG[i][k] = res;
}

void solve(void)
{
  string s; cin >> s;
  int K; cin >> K;
  int N = s.size();

  Tmp<cpp_int> t(N, K);
  boost::copy(s, t.S.begin());

  auto ans = t.recF(0, K);
  cout << ans << CRLF;
  return;
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  solve();

  return 0;
}
