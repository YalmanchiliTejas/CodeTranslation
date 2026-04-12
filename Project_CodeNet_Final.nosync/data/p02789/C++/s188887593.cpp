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
#include <iomanip>

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
template <typename T> inline T sum_value(vector<T>& x) { return accumulate(x.begin(), x.end(), 0ULL); }

int main() {
  ull n, m;
  cin >> n >> m;

  if (n == m) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
