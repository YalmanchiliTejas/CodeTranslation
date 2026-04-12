#include <stdio.h>
#include <map>

int main() {
  int ans = 0, n = 0;
  scanf("%d", &n);
  std::map<int, int> val;
  for (int i = 0; i < n; i++) {
  	int x;
    scanf("%d", &x);
    x = -x;
    auto iter = val.upper_bound(x);
    if (iter == val.end()) {
      ans++;
      if (val.find(x) == val.end()) {
        val[x] = 1;
      } else {
        val[x] += 1;
      }
    } else {
      iter->second--;
      if (iter->second == 0) {
        val.erase(iter);
      }
      if (val.find(x) == val.end()) {
        val[x] = 1;
      } else {
        val[x] += 1;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}