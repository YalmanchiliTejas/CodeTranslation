#include <bits/stdc++.h>

using namespace std;

int64_t P[60];
int64_t B[60];
int64_t L[60];

int64_t Solve(int64_t level, int64_t eat) {
  if (level <= 0) {
    if (eat >= 1) {
      return 1;
    } else {
      return 0;
    }
  }

  // B L P L B
  if (eat <= 1) {
    return 0;
  } else if (eat <= 1 + L[level - 1]) {
    return Solve(level - 1, eat - 1);
  } else if (eat <= 1 + L[level - 1] + 1) {
    return P[level - 1] + 1;
  } else if (eat <= 1 + L[level - 1] + 1 + L[level - 1]) {
    return P[level - 1] + 1 + Solve(level - 1, eat - 2 - L[level - 1]);
  } else {
    return P[level];
  }
}

int main() {
  int64_t N, eat;
  cin >> N >> eat;

  P[0] = 1;
  B[0] = 0;
  L[0] = 1;
  for (int level = 1; level <= 50; level++) {
    P[level] = P[level - 1] * 2 + 1;
    B[level] = B[level - 1] * 2 + 2;
    L[level] = P[level] + B[level];
  }

  printf("%ld\n", Solve(N, eat));

  return 0;
}
