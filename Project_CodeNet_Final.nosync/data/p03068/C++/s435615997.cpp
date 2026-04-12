#include <iostream>

int main() {
  size_t N;
  std::cin >> N;

  std::string buf;
  std::cin >> buf;
  const char* S = buf.c_str();

  size_t K;
  std::cin >> K;

  const char target = S[K-1];

  for (size_t i = 0; i < N; i++) {
    if (S[i] == target) {
      std::cout << S[i];
    } else {
      std::cout << "*";
    }
  }
  std::cout << std::endl;

  return 0;
}
