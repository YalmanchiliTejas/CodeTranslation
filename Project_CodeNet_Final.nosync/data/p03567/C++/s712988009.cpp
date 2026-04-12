#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <iomanip>

typedef long long ll;
const ll INF = (ll)1e18 + 1;
const ll MOD = 1e9 + 7;

template<class T> T maximum(T head, T tail) { return std::max(head, tail); }
template<class H, class... T> H maximum(H head, T... tail) { return std::max(head, maximum(tail...)); }

template<class T> T minimum(T head, T tail) { return std::min(head, tail); }
template<class H, class... T> H minimum(H head, T... tail) { return std::min(head, minimum(tail...)); }

template<class T> std::ostream& operator << (std::ostream& os, std::vector< T > v)
{
  ll i = 0;
  for (auto x : v) {os << " [" << i++ << "]" << x; if (i % 10 == 0) os << std::endl;}
  return os;
}

template<class T, class S> std::ostream& operator << (std::ostream& os, std::vector< std::pair<T, S> > vp)
{
  ll i = 0;
  for (auto p : vp) {os << " [" << i++ << "]" << p.first << " " << p.second; if (i % 10 == 0) os << std::endl;}
  return os;
}

void print(){ std::cout << std::endl; }
template<typename H> void print(H head) { std::cout << head << std::endl; }
template<typename H, typename... T> void print(H head, T... tail){ std::cout << head << " ", print(tail...); }

int main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  std::string s;
  std::cin >> s;

  if(s.find("AC") != std::string::npos) {
    print("Yes");
  } else {
    print("No");
  }
  return 0;
}
