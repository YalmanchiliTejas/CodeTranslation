#include <bits/stdc++.h>

using namespace std;

long long A[51], P[51];

long long count(int n, long long x) {
  if (n == 0) return x > 0 ? 1 : 0;
  if (x <= 1) return 0;
  if (x >= A[n]) return P[n];
  if (x <= 1 + A[n - 1]) return count(n - 1, x - 1);
  return 1 + P[n - 1] + count(n - 1, x - A[n - 1] - 2);
}

int main() {
  int N;
  long long X;
  cin >> N >> X;
  A[0] = P[0] = 1;
  for (int i = 1; i <= 50; i++) {
    A[i] = A[i - 1] * 2 + 3;
    P[i] = P[i - 1] * 2 + 1;
  }
  cout << count(N, X) << endl;

  return 0;
}
/* vim:set fdm=marker: */
