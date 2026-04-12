#include <stdio.h>
#include <stdlib.h>

#define MAX_N (50)
#define NUM_MOD (1000000007)

long solve(long l, long x, const long *hs, const long *ps) {
  // x == 0 or l == 0
  if (x == 0) {
    return 0;
  } else if (l == 0) {
    return 1;
  }
  // l > 0 and x > 0
  if (x < 2) {
    return 0;
  } else if (x < hs[l - 1] + 2) {
    return solve(l - 1, x - 1, hs, ps);
  } else if (x == hs[l - 1] + 2) {
    return ps[l - 1] + 1;
  } else if (x < 2 * hs[l - 1] + 3) {
    return ps[l - 1] + 1 + solve(l - 1, x - (hs[l - 1] + 2), hs, ps);
  } else {
    return ps[l];
  }
}

int main(int argc, char *argv[]) {
  // read inputs
  long N, X;
  scanf("%ld %ld", &N, &X);

  // calculate the height of the level l burgers
  long hs[MAX_N + 1], ps[MAX_N + 1];
  hs[0] = 1;
  ps[0] = 1;
  for (int l = 1; l <= N; l++) {
    hs[l] = 2 * hs[l - 1] + 3;
    ps[l] = 2 * ps[l - 1] + 1;
  }

  // solve
  printf("%ld\n", solve(N, X, hs, ps));

  return 0;
}
