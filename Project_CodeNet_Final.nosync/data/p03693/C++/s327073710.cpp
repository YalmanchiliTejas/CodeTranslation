#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

typedef long long ll;
const ll INF = (ll)1e18 + 1;
const ll MOD = 1e9 + 7;

template<typename T> T minimum(T head, T tail) { return std::min(head, tail); }
template<typename Head, typename... Tail> Head minimum(Head head, Tail... tail) {
  return std::min(head, minimum(tail...));
}

template<class T> std::ostream& operator << (std::ostream& os, std::vector< T > v)
{
  ll i = 0;
  for (auto x : v){os << " [" << i++ << "]" << x; if (i % 5 == 0) os << std::endl;}
  return os;
}

template<class T, class S> std::ostream& operator << (std::ostream& os, std::vector< std::pair<T, S> > vp)
{
  ll i = 0;
  for (auto p : vp){os << " [" << i++ << "]" << p.first << " " << p.second; if (i % 5 == 0) os << std::endl;}
  return os;
}

void print(){ std::cout << std::endl; }
template<typename H> void print(H head) { std::cout << head << std::endl; }
template<typename H, typename... T> void print(H head, T... tail){ std::cout << head << " ", print(tail...); }

int main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  //std::ostringstream oss;
  //oss << "ABC" << N;
  //std::string ans = oss.str();

  char r, g, b;
  std::cin >> r >> g >> b;

  ll x = r * 100 + g * 10 + b;
  if (x % 4 == 0) print("YES");
  else print("NO");

  return 0;
}
