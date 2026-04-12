#include <iostream>

int main()
{
  int A, B, C, X, Y;
  std::cin >> A >> B >> C >> X >> Y;

  // buy 2*c C pizza
  int ret = A * X + B * Y; // baseline
  // int a_max, b_max, c_max;
  for(int c=1; c <= 2 * std::max(X, Y); c++) {
    int a = std::max(0, X - c);
    int b = std::max(0, Y - c);
    int tmp = a*A + b*B + 2*c*C;

    if(tmp < ret) {
      ret = tmp;
      // a_max = a;
      // b_max = b;
      // c_max = 2*c;
    }
  }

  // std::cout << "ret: " << ret
  //           << " A: " << a_max
  //           << " B: " << b_max
  //           << " C:" << c_max
  //           << std::endl;

  std::cout << ret << std::endl;
  return 0;
}
