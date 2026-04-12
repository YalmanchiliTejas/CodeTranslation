#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  int c = n - 1;
  int d = -2;
  for (int i = 0; i < n; i++) {
    cout << xs[c] << " ";
    c += d;
    if (c == -1) {
      c = 0;
      d = 2;
    }
    if (c == -2) {
      c = 1;
      d = 2;
    }
  }
  cout << endl;
}