#include <cstdio>

using namespace std;

int n, h[22];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", h+i);
  int ma = 0, res = 0;
  for (int i = 0; i < n; i++) {
    res += (ma <= h[i] ? 1 : 0);
    if (ma < h[i]) ma = h[i];
  }
  printf("%d\n", res);
  return 0;
}
