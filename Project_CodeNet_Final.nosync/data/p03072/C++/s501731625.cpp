#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cmath>
#include <tuple>
#include <bitset>
#include <utility>
#include <climits>

#define push emplace_back
#define each(i, x) for (auto i=0; i < x; i++)
using ull = unsigned long long;
constexpr auto mod = 1000000007;
constexpr auto INF = ULLONG_MAX;

using namespace std;
template <typename T> inline void dump(const T& x) { cout << "[" << x << "]" << endl; }
template <typename T> inline void dump(const vector<T>& x) { for (const auto v : x) { cout << v << " "; } cout << endl; }
template <typename T> inline void sort_asc(vector<T>& x) { std::sort(x.begin(), x.end()); }
template <typename T> inline void sort_desc(vector<T>& x) { std::sort(x.begin(), x.end(), greater<T>()); }
template <typename T> inline T max_value(vector<T>& x) { return *max_element(x.begin(), x.end()); }
template <typename T> inline T min_value(vector<T>& x) { return *min_element(x.begin(), x.end()); }
template <typename T> inline T sum_value(vector<T>& x) { return accumulate(x.begin(), x.end(), 0); }

int main() {
  ull n;
  cin >> n;

  vector<ull> h;
  each(i, n) {
    ull tmp;
    cin >> tmp;
    h.push(tmp);
  }

  ull result = 1;
  auto first = h[0];
  vector<ull> bef;
  bef.push(h[0]);
  for (auto i=1; i < n; i++) {
    bool all = true;
    each(j, bef.size()) {
      if (h[i] >= bef[j]) {
      } else {
        all = false;
        break;
      }
    }

    if (all) {
      result++;
    }

    bef.push(h[i]);
  }

  cout << result << endl;


  return 0;
}
