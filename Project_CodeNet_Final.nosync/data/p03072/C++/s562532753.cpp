#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];

  int result = 1; // 一番西のは必ず海が見える
  int maxHeight = h[0];
  for (int i = 1; i < n; ++i) {
    if (h[i] >= maxHeight) {
      result++;
      maxHeight = h[i];
    }
  }
  cout << result << endl;

  return 0;
}
