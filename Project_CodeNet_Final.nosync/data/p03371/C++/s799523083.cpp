/* https://atcoder.jp/contests/abc095/tasks/arc096_a */

#include <iostream>

int solve(const int A, const int B, const int C, const int X, const int Y)
{
  int min_price = 1e5 * 5000 * 2;

  int max_num = std::max(X, Y);
  min_price = std::min(min_price, C*2*max_num);

  min_price = std::min(min_price, A*X + B*Y);

  if (X > Y) {
    min_price = std::min(min_price, C*2*Y + A*(X-Y));
  } else {
    min_price = std::min(min_price, C*2*X + B*(Y-X));
  }

  return min_price;
}

int main(int argc, char *argv[])
{
  // Input
  int A, B, C, X, Y;

  std::cin >> A >> B >> C >> X >> Y;

  // Output
  std::cout << solve(A, B, C, X, Y) << std::endl;

  return 0;
}
