#include <iostream>

int main() {
  int A, B, C, X, Y;
  std::cin >> A >> B >> C >> X >> Y;

  int answer = 1 << 30;

  answer = std::min(answer, X*A+Y*B);
  answer = std::min(answer, C*2*X+B*std::max(0, Y-X));
  answer = std::min(answer, A*std::max(0, X-Y)+C*2*Y);
  answer = std::min(answer, C*2*std::max(X,Y));

  std::cout << answer << std::endl;
}
