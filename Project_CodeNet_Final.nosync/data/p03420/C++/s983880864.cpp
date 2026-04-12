#include <cstdio>
#include <cstdint>
#include <algorithm>

int main() {
  intmax_t N, K;
  scanf("%jd %jd", &N, &K);

  intmax_t res=0;
  for (intmax_t b=K+1; b<=N; ++b) {
    intmax_t M=N-K+1;
    res += M/b*(b-K) + std::min(M%b, b-K);
    //fprintf(stderr, "%jd: %jd + %jd\n", b-K, M/b*(b-K), std::min(M%b, b-K));
  }

  if (K == 0)
    res -= N;

  printf("%jd\n", res);
}
