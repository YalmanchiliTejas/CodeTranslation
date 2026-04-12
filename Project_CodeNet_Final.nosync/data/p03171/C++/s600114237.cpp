#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAX_N (3000L)

using namespace std;

// dpsss[l][r][p] : The score X - Y that is realized when [l, r] is remaining
//                  and it is player p's turn
long dpsss[MAX_N][MAX_N][2];
long us[MAX_N][MAX_N];

void init(long N) {
  for (long l = 0; l < N; l++) {
    for (long r = l; r < N; r++) {
      us[l][r] = 0;
    }
  }
}

long calc_score(const long *as, long N, long l, long r, long p) {
  if (r < l) {
    return 0;
  }
  if (!us[l][r]) {
    dpsss[l][r][0] = max(as[l] + calc_score(as, N, l + 1, r, 1),
                         as[r] + calc_score(as, N, l, r - 1, 1));
    dpsss[l][r][1] = min(-as[l] + calc_score(as, N, l + 1, r, 0),
                         -as[r] + calc_score(as, N, l, r - 1, 0));
    us[l][r] = 1;
  }
  return dpsss[l][r][p];
}

int main() {
  // read inputs
  long N, as[MAX_N];
  scanf("%ld", &N);
  for (long i = 0; i < N; i++) {
    scanf("%ld", &as[i]);
  }

  // solve dp
  printf("%ld\n", calc_score(as, N, 0, N - 1, 0));
}