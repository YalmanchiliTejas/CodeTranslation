#include <cstdio>
#include <cstdint>

intmax_t ban(int n, intmax_t x) {
  fprintf(stderr, "%d %jd\n", n, x);
  if (!n) return x;
  if (!n || !x) return 0;
  intmax_t p = (2LL<<n)-1;
  intmax_t m = (4LL<<n)-3;
  fprintf(stderr, "%jd %jd\n", p, m);
  if (x >= m) return p;
  intmax_t res = 0;
  if (x > m/2) {
    res += ban(n-1, m/2-1);
    x -= m/2+1;
    res += 1;
    res += ban(n-1, x);
  } else {
    res += ban(n-1, x-1);
  }
  return res;
}

int main() {
  int n;
  intmax_t x;
  scanf("%d %jd", &n, &x);

  printf("%jd", ban(n, x));
}