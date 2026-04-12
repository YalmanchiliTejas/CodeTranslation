#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <utility>

#define MAX_MN (200000L)
#define MAX_FACT (MAX_MN)
#define NUM_MOD (1000000007L)

using namespace std;

long fs[MAX_FACT + 1], finvs[MAX_FACT + 1], invs[MAX_FACT + 1];

void combination_init() {
  fs[0] = fs[1] = 1;
  finvs[0] = finvs[1] = 1;
  invs[1] = 1;
  for (long i = 2; i <= MAX_FACT; i++) {
    fs[i] = fs[i - 1] * i % NUM_MOD;
    invs[i] = NUM_MOD - invs[NUM_MOD % i] * (NUM_MOD / i) % NUM_MOD;
    finvs[i] = finvs[i - 1] * invs[i] % NUM_MOD;
  }
}

long combination(long n, long k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fs[n] * (finvs[k] * finvs[n - k] % NUM_MOD) % NUM_MOD;
}

long mod(long n, long k) { return n % k >= 0 ? n % k : n % k + k; }

int main(int argc, char *argv[]) {
  // read inputs
  long N, M, K;
  scanf("%ld %ld %ld", &N, &M, &K);

  // combination init
  combination_init();

  // solve dp
  //   dp1ss[i][j] : sum of (|x1 - x2| + |y1 - y2|) for all pairs of
  //                 cells in a ixj grid
  //   dp2ss[i][j] : sum of (|x1 - x2| + |y1 - y2|) for all pairs of
  //                 cells where one cell is from area A and the other cell
  //                 is from area B in the diagram below.
  //                 Area A is a ixj grid.
  //                   |-------|-|
  //                   |-------|-|
  //                   |---A---|B|
  //                   |-------|-|
  //                   |-------|-|
  map<pair<long, long>, long> dp1ss, dp2ss;
  long s;
  // calculate dp2ss[N][0]
  dp2ss[make_pair(N, 0)] = 0;  // for convenience
  // calculate dp2ss[N][j]
  for (long j = 1; j < M; j++) {
    s = mod(N * (2 * j + N - 1) / 2, NUM_MOD);
    dp2ss[make_pair(N, j)] = mod(dp2ss[make_pair(N, j - 1)] + s, NUM_MOD);
    for (long k = 1; k < N; k++) {
      s = mod(s + k - (N - k), NUM_MOD);
      dp2ss[make_pair(N, j)] = mod(dp2ss[make_pair(N, j)] + s, NUM_MOD);
    }
  }
  // calculate dp1ss[N][0]
  dp1ss[make_pair(N, 1)] = 0;
  for (long d = 1; d < N; d++) {
    dp1ss[make_pair(N, 1)] = mod(dp1ss[make_pair(N, 1)] + d * (N - d), NUM_MOD);
  }
  // calculate dp1ss[N][j]
  for (long j = 2; j <= M; j++) {
    dp1ss[make_pair(N, j)] =
        mod(dp1ss[make_pair(N, j - 1)] + dp1ss[make_pair(N, 1)] +
                dp2ss[make_pair(N, j - 1)],
            NUM_MOD);
  }
  // printf("dp1ss[N][1] = %ld, dp2ss[N][1] = %ld\n", dp1ss[make_pair(N, 1)],
  //        dp2ss[make_pair(N, 1)]);
  // printf("dp1ss[N][M] = %ld, comb(NM-2, K-2) = %ld\n", dp1ss[make_pair(N, M)],
  //        combination(N * M - 2, K - 2));
  printf("%ld\n",
         mod(dp1ss[make_pair(N, M)] * combination(N * M - 2, K - 2), NUM_MOD));

  return 0;
}
