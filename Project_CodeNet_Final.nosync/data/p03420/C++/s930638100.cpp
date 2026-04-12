#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long i64;

int main() {
  i64 result = 0;
  int N, K;
  scanf("%d%d", &N, &K);
  if (K == 0) {
    printf("%lld\n", 1LL * N * N);
    return 0;
  }
  for (int b = K + 1; b <= N; ++b) {
    int len = b - K;
    int tot = N / b;
    result += 1LL * len * tot;
    int rem = N % b;
    if (rem != 0 && rem >= K) result += rem - K + 1;
  }

  printf("%lld\n", result);
  return 0;
}
