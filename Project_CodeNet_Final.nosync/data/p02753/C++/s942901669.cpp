#include <bits/stdc++.h>

#define whole(f, x, ...)                                 \
  ([&](decltype((x)) whole) {                            \
    return (f)(begin(whole), end(whole), ##__VA_ARGS__); \
  })(x)

using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  bool a = false, b = false;

  for (auto t : s) {
    if (t == 'A') a = true;
    if (t == 'B') b = true;
  }
  cout << (a && b ? "Yes" : "No") << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);

  solve();
  return 0;
}
