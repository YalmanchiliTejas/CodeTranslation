#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  vector<int> y = x;
  sort(y.begin(), y.end());
  int md = y[n >> 1];
  int nd = y[(n >> 1) - 1];
  for (int i = 0; i < n; i++) {
    if (x[i] >= md) {
      cout << nd << '\n';
    } else {
      cout << md << '\n';
    }
  }
  return 0;
}