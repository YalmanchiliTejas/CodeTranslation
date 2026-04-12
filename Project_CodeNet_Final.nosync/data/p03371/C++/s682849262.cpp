#include <cstdio>
#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)

int A, B, C, X, Y;

int main() {
  scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
  ll total = 0;
  total = A * X + B * Y;
  if (2 * C < A + B) {
    int x = (A + B) - 2 * C;
    total -= x * min(X, Y);
  }
  if (X > Y && A > 2 * C) {
    int d = A - 2 * C;
    total -= (X - Y) * d;
  } else if(Y > X && B > 2 * C) {
    int d = B - 2 * C;
    total -= (Y - X) * d;
  }
  printf("%lld\n", total);
}
