#include <bits/stdc++.h>

using namespace std;

int main() {
  int64_t A, B, C;
  int64_t X, Y;
  cin >> A >> B >> C >> X >> Y;

  int64_t minCost = 1LL << 60;
  for (int ci = 0; ci <= 2 * max(X, Y) + 10; ci += 2) {
    int ai = max(0L, X - ci / 2);
    int bi = max(0L, Y - ci / 2);
    int64_t cost = A * ai + B * bi + C * ci;
    minCost = min(minCost, cost);
  }
  printf("%ld\n", minCost);

  return 0;
}
