#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iomanip>

typedef long double ld;
typedef long long ll;
const ll INF = (ll)1e18 + 1;
const ll MOD = 1e9 + 7;

// Split
namespace util {

std::vector< std::string > split(std::string s, char delimiter)
{
  std::vector< std::string > vs;
  std::string sub;
  for (auto c : s) {
    if (c == delimiter) vs.push_back(sub), sub.clear();
    else sub += c;
  }
  vs.push_back(sub);
  return vs;
}

} // namespace util

// Minimum, Maximum
template<class T> T minimum(T head, T tail) { return std::min(head, tail); }
template<class H, class... T> H minimum(H head, T... tail) { return std::min(head, minimum(tail...)); }
template<class T> T maximum(T head, T tail) { return std::max(head, tail); }
template<class H, class... T> H maximum(H head, T... tail) { return std::max(head, maximum(tail...)); }

// Output
template<class T, class S> std::ostream& operator << (std::ostream& os, std::pair<T, S> p)
{
  return os << "(" << p.first << " " << p.second << ")";
}

template<class T> std::ostream& operator << (std::ostream& os, std::vector< T > v)
{
  for (ll i = 0; i < (ll)v.size(); i++){ os << " [" << i << "]" << v[i]; if (i % 10 == 9) os << std::endl; }
  //os << v[0]; for (ll i = 1; i < (ll)v.size(); i++){ os << " " << v[i]; }
  return os;
}

template<class T, class S> std::ostream& operator << (std::ostream& os, std::map< T, S > m)
{
  ll i = 0; for (auto p : m){ os << " [" << i << "]" << p.first << "->" << p.second; i++;}
  return os;
}

void print(){ std::cout << std::endl; }
template<typename H> void print(H head) { std::cout << head << std::endl; }
template<typename H, typename... T> void print(H head, T... tail){ std::cout << head << " ", print(tail...); }

// GCD, LCM
ll gcd(ll a, ll b) {
  while (b != 0) { a %= b; std::swap(a, b); }
  return a;
}
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  std::string S;
  std::cin >> S;

  std::string judge = "No";
  if (S.find("A") != std::string::npos && S.find("B") != std::string::npos) {
    judge = "Yes";
  }

  print(judge);
  return 0;
}
