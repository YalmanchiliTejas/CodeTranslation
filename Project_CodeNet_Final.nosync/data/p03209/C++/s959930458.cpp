#include <cstdio>
using namespace std;
long A[50], P[50];

long f(int N, long X) {
  if (N == 0) {
    if (X <= 0) return 0;
    else return 1;
  } else if (X <= 1 + A[N-1]) {
    return f(N-1, X-1);
  } else {
    return P[N-1] + 1 + f(N-1, X-2-A[N-1]);
  }
}

int main() {
  int N;
  long X;
  scanf("%d %ld", &N, &X);
  A[0] = P[0] = 1;
  for (int i=1; i<N; i++) {
    A[i] = 2 * A[i-1] + 3;
    P[i] = 2 * P[i-1] + 1;
  }
  printf("%ld\n", f(N, X));
}
