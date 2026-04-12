#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int>a(n);
  long long s = 0;
  for (int i = 0; i < n; i++) cin >> a[i], s += a[i];
  vector<vector<long long>>dpX(n + 1, vector<long long>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    dpX[i][i] = a[i-1];
  }
  for (int l = 1; l <= n; ++l) {
    for (int i = 1; i <= n - l; i++) {
      int j = i + l;
      if (j == i + 1) {
        dpX[i][j] = max(a[i-1], a[j-1]);
        continue;
      }
      long long first = a[i-1] + min(dpX[i+1][j-1], dpX[i+2][j]);
      long long last = a[j-1] + min(dpX[i][j-2], dpX[i+1][j-1]);
      dpX[i][j] = max(first, last);
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = i + 1; j <= n; j++) {
  //     if (j == i + 1) {
  //       dpX[i][j] = max(a[i-1], a[j-1]);
  //       continue;
  //     }
  //     long long first = a[i-1] + min(dpX[i+1][j-1], dpX[i+2][j]);
  //     long long last = a[j-1] + min(dpX[i][j-2], dpX[i+1][j-1]);
  //     dpX[i][j] = max(first, last);
  //     cout << i << " " << j << " " << dpX[i][j] << endl;
  //   }
  // }
  cout << 2 * dpX[1][n] - s << endl;
  return 0;
}