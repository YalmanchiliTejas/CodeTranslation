#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <numeric>

using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define input(...) __VA_ARGS__; in(__VA_ARGS__)

#if __has_include("debugger.cpp")
  #include "debugger.cpp"
#else
void print() {
  std::cout << std::endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(tail) > 0) cout << " ";
  print(std::forward<Tail>(tail)...);
}
# endif

void in() { }

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
  cin >> head;
  in(std::forward<Tail>(tail)...);
}

int main() {
  ll input(n);
  vector<ll> a(n);
  REP(i, n) cin >> a[i];

  vector<ll> table(n + 1, 0);
  table[0] = -(1ll << 60);
  REP(i, n) {
    ll index = distance(table.begin(), upper_bound(table.begin(), table.end(), -(a[i] + 1)) - 1);
    table[index + 1] = -(a[i] + 1);
  }
  table.push_back(0);
  REP(i, table.size()) {
    if (table[i] == 0) {
      print(i - 1);
      break;
    }
  }
}
