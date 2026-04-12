#include <iostream>

int main(void) {

  int N, M;
  std::cin >> N >> M;

  if (N == M) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}