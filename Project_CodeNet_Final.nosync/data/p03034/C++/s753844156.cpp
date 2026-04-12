#include <bits/stdc++.h>

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<long long>> v1(n + 1), v2(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n; j += i) {
      v1[i].push_back(a[j]);
    }
    for (int j = n - 1; j >= 0; j -= i) {
      v2[i].push_back(a[j]);
    }
    for (int j = 1; j < v1[i].size(); j++) {
      v1[i][j] += v1[i][j - 1];
    }
    for (int j = 1; j < v2[i].size(); j++) {
      v2[i][j] += v2[i][j - 1];
    }
  }
  vector<vector<int>> pr(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      pr[j].push_back(i);
    }
  }
  long long ans = 0;
  for (int A = 1; A < n - 1; A++) {
    for (auto z : pr[n - 1 - A]) {
      if (z >= A) continue;
      int B = A - z;
      if (A <= n - 1 - A && A % z == 0) continue;
      long long sum = v1[z][(n - 1 - A) / z] + v2[z][(n - 1 - A) / z];
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}
