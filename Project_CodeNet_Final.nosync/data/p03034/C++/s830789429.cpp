// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
#include<bitset>
#include<cstdlib>
// #include<deque>
// #include<multiset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

// #undef DEBUG
// #define DEBUG
// DEBUG {{{
#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <valarray>
#include <vector>
template < int n, class... T >
typename std::enable_if< (n >= sizeof...(T)) >::type __output_tuple(
    std::ostream &, std::tuple< T... > const &) {}
template < int n, class... T >
typename std::enable_if< (n < sizeof...(T)) >::type __output_tuple(
    std::ostream &os, std::tuple< T... > const &t) {
  os << (n == 0 ? "" : ", ") << std::get< n >(t);
  __output_tuple< n + 1 >(os, t);
}
template < class... T >
std::ostream &operator<<(std::ostream &os, std::tuple< T... > const &t) {
  os << "(";
  __output_tuple< 0 >(os, t);
  os << ")";
  return os;
}
template < class T, class U >
std::ostream &operator<<(std::ostream &os, std::pair< T, U > const &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template < class T >
std::ostream &operator<<(std::ostream &os, const std::stack< T > &a) {
  os << "{";
  for(auto tmp = a; tmp.size(); tmp.pop())
    os << (a.size() == tmp.size() ? "" : ", ") << tmp.top();
  os << "}";
  return os;
}
template < class T, class Container, class Compare >
std::ostream &operator<<(std::ostream &os,
    std::priority_queue< T, Container, Compare > a) {
  os << "{ (top) ";
  while(a.size()) os << a.top() << (a.size() == 1 ? "" : ", "), a.pop();
  os << " }";
  return os;
}
template < class T, class Container >
std::ostream &operator<<(std::ostream &os, std::queue< T, Container > a) {
  os << "{ ";
  while(a.size()) os << a.front() << (a.size() == 1 ? "" : ", "), a.pop();
  os << " }";
  return os;
}
#ifdef DEBUG
#if !defined(DEBUG_OUT)
// #define DEBUG_OUT std::cerr
#endif
#define dump(...)                                                                \
  [&]() {                                                                        \
    auto __debug_tap = std::make_tuple(__VA_ARGS__);                             \
    DEBUG_OUT << "[" << __LINE__ << "] " << #__VA_ARGS__ << " = " << __debug_tap \
    << std::endl;                                                      \
  }()
template < class T >
inline void dump2D(T &d, size_t sizey, size_t sizex) {
  for(size_t i = 0; i < sizey; i++) {
    DEBUG_OUT << "\t";
    for(size_t j = 0; j < sizex; j++)
      DEBUG_OUT << d[i][j] << (j + 1 == sizex ? "" : "\t");
    DEBUG_OUT << std::endl;
  }
}
template < class T >
inline void dump1D(T &d, size_t sizey) {
  for(size_t i = 0; i < sizey; i++) {
    DEBUG_OUT << d[i] << (i + 1 == sizey ? "" : " ");
  }
  DEBUG_OUT << std::endl;
}
template <
class T, class = typename std::iterator_traits< decltype(begin(T())) >::value_type,
      class = typename std::enable_if< !std::is_same< T, std::string >::value >::type >
      std::ostream &operator<<(std::ostream &os, const T &a) {
        os << "{";
        for(auto ite = begin(a); ite != end(a); ++ite)
          os << (ite == begin(a) ? "" : ", ") << *ite;
        os << "}";
        return os;
      }
#else
#define dump(...) ((void) 42)
#define dump2D(...) ((void) 42)
#define dump1D(...) ((void) 42)
template <
class T, class = typename std::iterator_traits< decltype(begin(T())) >::value_type,
      class = typename std::enable_if< !std::is_same< T, std::string >::value >::type >
      std::ostream &operator<<(std::ostream &os, const T &a) {
        for(auto ite = begin(a); ite != end(a); ++ite)
          os << (ite == begin(a) ? "" : " ") << *ite;
        return os;
      }
#endif
// }}}


int n;
ll s[112345];

// O(N^.5)
/// --- divisor {{{ ///
#include <vector>
vector< ll > divisor(ll n) {
  vector< ll > res;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      res.emplace_back(i);
      if(i != n / i) res.emplace_back(n / i);
    }
  }
  return res;
}
/// }}}--- ///

vector<ll> sumHead[112345];
vector<ll> sumTail[112345];

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> s[i];
  ll ans = 0;

  for(int i = 1; i <= n; i++) {
    sumHead[i].push_back(0);
    sumTail[i].push_back(0);
    for(int j = i; j < n; j += i) {
      sumHead[i].push_back(s[j] + sumHead[i].back());
      sumTail[i].push_back(s[n-1-j] + sumTail[i].back());
    }
  }

  for(int A = 2; A <= n - 2; A++) {
    int r = n - 1 - A;
    auto ds = divisor(r);
    for(auto d : ds) {
      int times = r / d + 1;
      if(d >= A) continue;
      if(A <= ll(d) * (times-1) && A % d == 0) continue;
      ll res = sumHead[d].at(times-1);
      res += sumTail[d].at(times-1);
      ans = max(ans, res);
      dump(res, d, times, A);
    }
  }
  cout << ans << endl;
  return 0;
}
