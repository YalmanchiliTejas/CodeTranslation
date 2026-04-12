#include<iostream>
#include<cmath>
using namespace std;
using ll = long long;

int A, B, C, X, Y;

int main() {
  scanf("%d%d%d%d%d", &A, &B, &C, &X, &Y);

  ll sum = 0;

  // AピザとBピザを1枚ずつ買う場合とABピザを2枚買う場合にどちらが高いかを調べる
  if (A + B <= 2 * C) {
    sum = A * X + B * Y;
  }
  else {
    // 出来る限りABピザを買う
    if (X < Y) {
      sum = 2 * C * X + B * (Y - X);
      if (sum > 2 * C * Y) sum = 2 * C * Y;
    }
    else {
      sum = 2 * C * Y + A * (X - Y);
      if (sum > 2 * C * X) sum = 2 * C * X;
    }
  }

  printf("%lld\n", sum);
  return 0;
}