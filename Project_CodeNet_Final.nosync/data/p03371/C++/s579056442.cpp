#include <algorithm>
#include <iostream>
#include <array>

int main()
{
  int A, B, C, X, Y;
  std::cin >> A >> B >> C >> X >> Y;

  // don't buy C
  int ret_ab = A * X + B * Y;

  // mixture of A, B, C
  int c = std::min(X, Y);
  int a = std::max(0, X - c);
  int b = std::max(0, Y - c);
  int ret_abc = a*A + b*B + 2*c*C;

  // all C
  int ret_c = 2 * std::max(X, Y) * C;

  std::array<int, 3> candidates = {ret_ab, ret_abc, ret_c};
  auto ret = std::min_element(candidates.begin(),
                              candidates.end());

  std::cout << *ret << std::endl;
  return 0;
}
