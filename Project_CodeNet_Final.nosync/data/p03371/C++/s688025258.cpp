#include <iostream>

using namespace std;

int main() {
  int A, B, C, X, Y;
  scanf("%d%d%d%d%d", &A, &B, &C, &X, &Y);

  printf("%d\n", min(A * X + B * Y, min(2 * C * max(X, Y), 2 * C * min(X, Y) + (X > Y ? A * (X - Y) : B * (Y - X)))));
  return 0;
}
