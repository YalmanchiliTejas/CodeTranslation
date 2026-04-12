#include <algorithm>  //min, max, sort, unique, fill
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>  //pair, swap,
#include <vector>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) for (ll i = 0; i < (n); i++)

int main() {
  int a;
  cin >> a;
  cout << (a == 7 || a == 5 || a == 3 ? "YES" : "NO") << endl;
  return 0;
}
