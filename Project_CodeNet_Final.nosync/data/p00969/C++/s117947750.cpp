#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

int find(std::vector<int>& a, int x) {
  int upper = std::upper_bound(a.begin(), a.end(), x) - a.begin();
  int lower = std::lower_bound(a.begin(), a.end(), x) - a.begin();
  if (upper - lower > 0) return lower;
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  std::sort(a.begin(), a.end());
  std::vector<std::vector<int>> used(n, std::vector<int>(n, 0));
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (used[i][j]) continue;
      used[i][j] = true;
      int d = a[j] - a[i];
      int len = 2;
      int x = a[j];
      int k = j;
      while (true) {
        int next = find(a, x + d);
        if (next < 0) break;
        used[k][next] = true;
        k = next;
        ++len;
        x += d;
      }
      ans = std::max(ans, len);
    }
  }
  std::cout << ans << std::endl;
  return 0;
}

