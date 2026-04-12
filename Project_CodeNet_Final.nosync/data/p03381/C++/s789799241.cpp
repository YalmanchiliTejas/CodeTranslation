#include <algorithm>
#include <cstdio>

const int N = 200050;

int n, A[N], B[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &A[i]);
    B[i] = A[i];
  }
  std::sort(A, A + n);
  for (int i = 0; i < n; ++i)
    printf("%d\n", B[i] >= A[n / 2] ? A[n / 2 - 1] : A[n / 2]);
  return 0;
}
