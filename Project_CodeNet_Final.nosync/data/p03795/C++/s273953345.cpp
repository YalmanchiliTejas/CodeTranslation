
#include "bits/stdc++.h"

// clang-format off
template <typename T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template <typename T> T lcm(T a, T b) { return a * b / gcd(a, b); }
template <typename T> T clamp(T val, T min, T max) { return val < min ? min : (max < val ? max : val); }
char capitalize(char c) { return static_cast<char>(std::toupper(static_cast<unsigned char>(c))); }
// template <typename T> size_t max_index(T begin, T end) { return distance(begin, max_element(begin, end)); }
// template <typename T> size_t min_index(T begin, T end) { return distance(begin, min_element(begin, end)); }
// clang-format on

// #define int long long
#define YES "YES"
#define NO  "NO"

using namespace std;

signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int num = 0;
  // num = numeric_limits<int>::max();
  // num = numeric_limits<int>::min();
  bool flag = false;
  // flag = true;

  int n; cin >> n;

  num = 800 * n - 200 * (n / 15);
  
  cout << num << endl;
  // cout << (flag ? "H" : "D") << endl;
  
  return 0;
}
