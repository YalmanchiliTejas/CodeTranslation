#include <iostream>

int main() {

  int N;
  std::string S;
  int K;

  std::cin >> N >> S >> K;

  char tmp;
  tmp = S[K - 1];
  for (int i = 0; i < N; i++) {
    if (S[i] == tmp) {
      continue;
    } else {
      S[i] = '*';
    }
  }
  std::cout << S << std::endl;
  return 0;
}