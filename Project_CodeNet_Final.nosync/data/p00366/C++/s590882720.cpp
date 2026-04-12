#include <stdio.h>
#include <vector>

int main(void) {
  int n, i, j, max = 0, ans = 0;
  scanf("%d", &n);
  int t[n];
  std::vector<int> v;
  for(i = 0; i < n; ++i) {
    scanf("%d", &t[i]);
    if(max < t[i]) max = t[i];
  }
  for(i = 1; i <= max; ++i) if(!(max % i)) v.push_back(i);
  for(i = 0; i < n; ++i) {
    for(j = 0;; ++j) {
      if(v[j] >= t[i]) {
        ans += v[j] - t[i];
        break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
