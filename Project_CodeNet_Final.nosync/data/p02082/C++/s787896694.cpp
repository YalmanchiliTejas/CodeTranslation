#include <cstdio>
#include <cstdint>

int main() {
  intmax_t s, t, p, q, M, y;
  scanf("%jd %jd %jd %jd %jd %jd", &s, &t, &p, &q, &M, &y);

  printf("%jd\n", s^t^y);
}

