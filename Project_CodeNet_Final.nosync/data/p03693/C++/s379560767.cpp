#include <bits/stdc++.h>

using namespace std;

typedef long long int llint;

int r, g, b;

inline bool solve() {
  return (100 * r + 10 * g + b) % 4 == 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> r >> g >> b;

  if (solve()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}