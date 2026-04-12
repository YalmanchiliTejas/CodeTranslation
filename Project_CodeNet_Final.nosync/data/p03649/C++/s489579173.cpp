#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

template<class T> inline bool UpdateMin(T& a, T b) {
  if (a > b) { a = b; return 1; } return 0;
}

template<class T> inline bool UpdateMax(T& a, T b) {
  if (a < b) { a = b; return 1; } return 0;
}

int64 Solve() {
  int n;
  cin >> n;
  vector<int64> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  auto check_fn = [&]() -> bool {
    for (int i = 0; i < n; i++) {
      if (xs[i] >= n) return false;
    }
    return true;
  };
  if (check_fn()) return 0;

  int64 count = 0;
  do {
    for (int i = 0; i < n; i++) {
      int64 q = xs[i] / n;
      xs[i] -= q * n;
      for (int j = 0; j < n; j++) {
        if (j == i) continue;
        xs[j] += q;
      }
      count += q;
    }
  } while (!check_fn());
  return count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cout << Solve() << endl;
}