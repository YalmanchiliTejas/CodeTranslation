#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    auto v = vector<int>(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(begin(v), end(v));
    int s = accumulate(begin(v) + 1, end(v) - 1, 0);
    cout << s / (n - 2) << endl;
  }
  return 0;
}

