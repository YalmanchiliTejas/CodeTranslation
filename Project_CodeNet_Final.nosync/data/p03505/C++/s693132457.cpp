#include <cstdio>
typedef long long LL;
int main() {
  LL N, A, B;
  scanf("%lld%lld%lld", &N, &A, &B);
  if (A >= N) printf("1\n");
  else if (A <= B) printf("-1\n");
  else {
    N -= A;
    printf("%lld\n", (N + A - B - 1) / (A - B) * 2 + 1);
  }
  return 0;
}