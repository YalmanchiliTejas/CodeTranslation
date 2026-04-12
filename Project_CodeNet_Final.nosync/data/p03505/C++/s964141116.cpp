#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdint>

int main() {
  intmax_t K, A, B;
  scanf("%jd %jd %jd", &K, &A, &B);

  if (K <= A)
    return !printf("1\n");

  if (A <= B)
    return !printf("-1\n");

  printf("%jd\n", 1+(K-B-1)/(A-B)*2);
}
