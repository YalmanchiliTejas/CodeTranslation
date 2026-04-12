#include "bits/stdc++.h"

using namespace std;

const int MAX_N = 3000;

int a[MAX_N];
long long Solve[MAX_N][MAX_N];

long long solve(int i, int j) {
  if (Solve[i][j] == -1) {
    if (i == j) {
      Solve[i][j] = a[i];
    } else {
      Solve[i][j] = std::max(a[i] - solve(i + 1, j), a[j] - solve(i, j - 1));
    }
  }
  return Solve[i][j];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      Solve[i][j] = -1;
    }
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  long long answer = solve(0, n - 1);
  printf("%lld\n", answer);
  return 0;
}
