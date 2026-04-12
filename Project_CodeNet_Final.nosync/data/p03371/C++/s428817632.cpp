#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/integer/common_factor.hpp>
#include <boost/integer/common_factor_rt.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

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

typedef uintmax_t    ull;
typedef intmax_t     ll;
typedef uint64_t     ul;
typedef uint32_t     ui;
typedef uint8_t      uc;

typedef boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1000>> cpp_dec_float_1000;

constexpr char CRLF = '\n';
constexpr char SPACE = ' ';
constexpr char VECTOR_COUT_SEPARATOR = SPACE;
constexpr ll INF = 1000'000'007;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> std::ostream& operator<< (std::ostream& os, const std::vector<T>& vc) { for(auto it = vc.begin(); it != vc.end(); ++it) { if (std::next(it) == vc.end()) os << *it; else os << *it << VECTOR_COUT_SEPARATOR; } return os; }
template<class T1, class T2> inline std::ostream & operator<< (std::ostream & os, const std::pair<T1, T2> & p) { return os << p.first << ' ' << p.second; }

void solve(void)
{
  ll A, B, C; cin >> A >> B >> C;
  C *= 2;
  ll X, Y; cin >> X >> Y;
  ll res{};
  if(C <= A + B){
    while(X > 0 && Y > 0){
      res += C;
      --X; --Y;
    }
  }
  if(C <= B){
    while(Y > 0){
      res += C;
      --X; --Y;
    }
  }
  if(C <= A){
    while(X > 0){
      res += C;
      --X; --Y;
    }
  }
  while(X > 0){
    res += A;
    --X;
  }
  
  while(Y > 0){
    res += B;
    --Y;
  }

  cout << res << CRLF;
  return;
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  solve();

  return 0;
}
