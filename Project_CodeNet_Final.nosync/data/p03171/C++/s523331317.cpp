#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n; cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<vector<int64_t>> max_diff(n, vector<int64_t>(n));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j <= n - 1; j++) {
      if (i == j) {
        max_diff[i][j] = (int64_t)a[i];
      } else {
        max_diff[i][j] = (int64_t)max(a[i] - max_diff[i + 1][j], a[j] - max_diff[i][j - 1]);
      }
    }
  }

  cout << max_diff[0][n - 1] << "\n";
  return 0;
}