#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

#define EPS (1e-7)

constexpr ll Maisu(ll level) { return level == 0 ? 1 : 3 + Maisu(level - 1) * 2; }
constexpr ll Maisus[51] = {
    Maisu(0),  Maisu(1),  Maisu(2),  Maisu(3),  Maisu(4),  Maisu(5),  Maisu(6),  Maisu(7),
    Maisu(8),  Maisu(9),  Maisu(10), Maisu(11), Maisu(12), Maisu(13), Maisu(14), Maisu(15),
    Maisu(16), Maisu(17), Maisu(18), Maisu(19), Maisu(20), Maisu(21), Maisu(22), Maisu(23),
    Maisu(24), Maisu(25), Maisu(26), Maisu(27), Maisu(28), Maisu(29), Maisu(30), Maisu(31),
    Maisu(32), Maisu(33), Maisu(34), Maisu(35), Maisu(36), Maisu(37), Maisu(38), Maisu(39),
    Maisu(40), Maisu(41), Maisu(42), Maisu(43), Maisu(44), Maisu(45), Maisu(46), Maisu(47),
    Maisu(48), Maisu(49), Maisu(50)};

constexpr ll Putty(ll level) { return level == 0 ? 1 : 1 + Putty(level - 1) * 2; }
constexpr ll Puttys[51] = {
    Putty(0),  Putty(1),  Putty(2),  Putty(3),  Putty(4),  Putty(5),  Putty(6),  Putty(7),
    Putty(8),  Putty(9),  Putty(10), Putty(11), Putty(12), Putty(13), Putty(14), Putty(15),
    Putty(16), Putty(17), Putty(18), Putty(19), Putty(20), Putty(21), Putty(22), Putty(23),
    Putty(24), Putty(25), Putty(26), Putty(27), Putty(28), Putty(29), Putty(30), Putty(31),
    Putty(32), Putty(33), Putty(34), Putty(35), Putty(36), Putty(37), Putty(38), Putty(39),
    Putty(40), Putty(41), Putty(42), Putty(43), Putty(44), Putty(45), Putty(46), Putty(47),
    Putty(48), Putty(49), Putty(50)};

ll calc(ll n, ll x) {
  if (x >= Maisus[n]) {
    return Puttys[n];
  }

  const ll mid = Maisus[n] / 2 + 1;
  if (x <= n) {
    return 0;
  } else if (x < mid) {
    return calc(n - 1, x - 1);
  } else if (x == mid) {
    return Puttys[n - 1] + 1;
  } else {
    return Puttys[n - 1] + 1 + calc(n - 1, x - 2 - Maisus[n - 1]);
  }
}

int main() {
  ll N, X;
  cin >> N >> X;

  const ll ans = calc(N, X);
  cout << ans << endl;
  return 0;
}
