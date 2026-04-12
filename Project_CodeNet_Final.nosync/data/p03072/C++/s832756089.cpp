#include <iostream>

int main() {
  int N;
  std::cin >> N;
  int Hmax = 1;
  int H;
  int Output = N;
  for (int i = 1; i <= N; ++i) {
    std::cin >> H;
    if (H < Hmax) {
      --Output;
    } else {
      Hmax = H;
    }
  }
  std::cout << Output << "\n";
  return 0;
}