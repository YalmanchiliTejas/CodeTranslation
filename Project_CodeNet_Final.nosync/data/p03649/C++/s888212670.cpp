#include <cstdio>

long long a[1234];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
  }
  long long k = 0;
  while (true) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
      if (pos < 0 || a[i] > a[pos]) pos = i;
    }
    if (a[pos] < n) break;
    long long add = a[pos] / n;
    a[pos] %= n;
    for (int i = 0; i < n; i++) if (i != pos) a[i] += add;
    k += add;
  }
  printf("%lld\n", k);
}
