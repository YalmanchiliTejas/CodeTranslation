#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  // read inputs
  int N, K;
  scanf("%d %d", &N, &K);

  // count for each b
  long ans = 0;
  for (int b = K + 1; b <= N; b++) {
    const int num_cycle = N / b;
    const int cnt_full = num_cycle * (b - K);
    const int cnt_part = max(N - num_cycle * b - max(K - 1, 0), 0);
    ans += cnt_full + cnt_part;
  }
  printf("%ld\n", ans);

  return 0;
}
