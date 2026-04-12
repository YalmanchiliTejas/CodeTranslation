#include <cstdio>

using namespace std;

const int N = 100'009;

int a[N];
int f[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; ++i) {
    f[i] = -1;
  }
  for (int i = 0; i < n; ++i) {
    int l = -1, r = n;
    while (r - l > 1) {
      int s = (l + r) / 2;
      if (a[i] <= f[s]) {
        l = s;
      } else {
        r = s;
      }
    }
    f[l + 1] = a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (f[i] != -1) {
      ++ans;
    }
  }
  printf("%d\n", ans);
}
