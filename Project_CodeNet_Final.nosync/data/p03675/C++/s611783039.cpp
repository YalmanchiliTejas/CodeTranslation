// #define STOPIT
#include <bits/stdc++.h>
#define loop(n) for (lint ngtkana_is_a_genius = 0; ngtkana_is_a_genius < lint(n); ngtkana_is_a_genius++)
#define rep(i, begin, end) for (lint i = lint(begin); (i) < lint(end); i++)
#define all(v) v.begin(), v.end()
#define rand(l, r) std::uniform_int_distribution<>(l, r)(mt)
using lint = long long;
auto mt = std::mt19937_64(std::random_device{}());
auto cmn = [](auto& a, auto b){ if (a > b) {a = b; return true;} return false; };
auto cmx = [](auto& a, auto b){ if (a < b) {a = b; return true;} return false; };
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail) { std::cerr << " " << head; debug_impl(tail...); }
#ifndef STOPIT
#define debug(...)\
  do {\
    std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
    debug_impl(__VA_ARGS__);\
    std::cerr << std::noboolalpha;\
  } while (false)
#else
#define debug(...) {}
#endif

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr>
std::istream& operator>> (std::istream& is, Container& v)
  { for (auto & x : v) { is >> x; } return is; }

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr >
std::ostream& operator<< (std::ostream& os, Container const& v) {
 os << "{";
  for (auto it = v.begin(); it != v.end(); it++)
    {os << (it != v.begin() ? "," : "") << *it;}
  return os << "}";
}

int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int n; std::cin >> n;
  std::vector<int> a(n); std::cin>>a;

  std::vector<int> odd, even;
  rep(i,0,n) {
    (i%2==0 ? even : odd).emplace_back(i);
  }
  std::vector<int> ord;
  ord.insert(ord.end(), even.rbegin(), even.rend());
  ord.insert(ord.end(), odd.begin(), odd.end());
  if (ord.front() != n-1) {
    std::reverse(all(ord));
  }

  std::vector<int> ans(n);
  rep(i,0,n) {
    ans.at(i) = a.at(ord.at(i));
  }
  rep(i,0,n) {
    std::cout<<(0 < i ? " " : "") << ans.at(i);
  }
  std::cout << std::endl;
  return 0;
}