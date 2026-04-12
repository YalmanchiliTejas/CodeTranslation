#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// claudio van
int main() {
  int n; scanf("%d", &n);
  int cnt = 0;
  int mx = -1;
  for (int i = 0; i < n; ++i) {
    int h; scanf("%d", &h);
    mx = max(mx, h);
    if (mx == h) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}