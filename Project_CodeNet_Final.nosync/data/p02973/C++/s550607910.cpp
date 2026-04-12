#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> xs(n);
  for (int i = 0; i < n; i++) cin >> xs[i];

  vector<int> hs(n, -1);
  for (int x : xs) {
    if (hs[0] < x) {
      hs[0] = x;
    } else {
      int l = 0;
      int r = n - 1;
      while (r - l >= 2) {
        int m = (r + l) / 2;
        if (hs[m] < x) {
          r = m;
        } else {
          l = m;
        }
      }
      hs[r] = x;
    }
  }

  int answer = n - count(hs.begin(), hs.end(), -1);
  cout << answer << endl;
}
