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

void print(){ std::cout << std::endl; }
template<typename H> void print(H head) { std::cout << head << std::endl; }
template<typename H, typename... T> void print(H head, T... tail){ std::cout << head << " ", print(tail...); }
template<typename V> void printVec(V v) {ll i=0;for(auto x : v){std::cout << " [" << i++ << "] " << x;} print();}

int main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll N;
  std::cin >> N;
  std::vector< ll > vh(N, 0LL);
  for (ll i = 0; i < N; i++) {
    std::cin >> vh[i];
  }

  ll ans = 0LL;
  for (ll i = 0; i < N; i++) {
    bool judge = true;
    for (ll j = 0; j < i; j++) {
      if (vh[i] < vh[j]) {
	judge = false;
      }
    }
    if (judge) ans++;
  }

  print(ans);
  return 0;
}
