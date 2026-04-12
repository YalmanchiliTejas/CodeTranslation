#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

using ll = long long;

template <class T>
using grid = vector<vector<T>>;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define input(...) __VA_ARGS__; in(__VA_ARGS__)

void print() {
  std::cout << std::endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  std::cout << head << " ";
  print(std::forward<Tail>(tail)...);
}

void in() { }

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
  cin >> head;
  in(std::forward<Tail>(tail)...);
}

int main() {
  ll input(a, b, c, x, y);

  set<ll> cost;
  for(ll ab = 0; ab <= max(x, y) * 2; ab += 2) {
    cost.insert(max(0ll, (x - ab / 2)) * a + max(0ll, (y - ab / 2)) * b + ab * c);
  }

  print(*cost.begin());
}
