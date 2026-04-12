#include <iostream>
using namespace std;
using int64 = int_fast64_t;

int64 memo[55];
int64 p_memo[55];

int64 f(int64 L) {
  if (memo[L] > 0) return memo[L];
  if (L == 0) return memo[0] = 1;
  return memo[L] = 2 * f(L-1) + 3;
}

int64 getP(int64 L) {
  if (p_memo[L] > 0) return p_memo[L];
  if (L == 0) return p_memo[0] = 1;
  return p_memo[L] = 2 * getP(L-1) + 1;
}

int64 solve(int64 L, int64 X) {
  if (X == 0) {
    return 0;
  } else if (L == 0) {
    return 1;
  } else if (X <= 1 + f(L-1)) {
    return solve(L-1, X-1);
  } else if (X <= 2 + f(L-1)) {
    return getP(L-1) + 1;
  } else if (X <= 2 + 2*f(L-1)) {
    return getP(L-1) + 1 + solve(L-1, X-f(L-1)-2);
  } else {
    return getP(L-1) + 1 + solve(L-1, X-f(L-1)-2);
  }
}

int main() {
  int64 N, X;
  cin >> N >> X;
  f(N);
  getP(N);
  
  int64 ans = solve(N, X);
  cout << ans << endl;
}
