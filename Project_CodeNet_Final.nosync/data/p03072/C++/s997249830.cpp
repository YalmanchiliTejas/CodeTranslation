
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// clang-format off
template <typename T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template <typename T> T lcm(T a, T b) { return a * b / gcd(a, b); }
template <typename T> T clamp(T val, T min, T max) { return val < min ? min : (max < val ? max : val); }
template <typename T> size_t max_index(T begin, T end) { return distance(begin, max_element(begin, end)); }
template <typename T> size_t min_index(T begin, T end) { return distance(begin, min_element(begin, end)); }
// clang-format on

#define int long long
#define YES "Yes"
#define NO  "No"

using namespace std;

signed main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int num = 0;

  int n; cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; ++i) cin >> v[i];

  num = 0;
  for (int i = 0; i < n; ++i) {
    bool flag = true;
    for (int j = 0; j < i; ++j) {
      if (v[j] > v[i]) flag = false;
      if (!flag) break;
    }
    if (flag) ++num;
  }
  
  cout << num << endl;
  
  return 0;
}
