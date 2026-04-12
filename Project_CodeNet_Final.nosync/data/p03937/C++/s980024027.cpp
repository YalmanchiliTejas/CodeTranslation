#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  int cnt = 0;
  for (int i = 0; i < h * w; i++) {
    char c;
    cin >> c;
    if (c == '#') cnt++;
  }
  if (cnt == h + w - 1) {
    cout << "Possible" << '\n';
  } else {
    cout << "Impossible" << '\n';
  }
  return 0;
}