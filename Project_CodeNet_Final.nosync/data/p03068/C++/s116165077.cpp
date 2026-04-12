#include <iostream>

int main() {
  int N, K;
  char S[11];
  
  std::cin >> N >> S >> K;

  const char C = S[K-1];

  for (char* p=S; *p!='\0'; ++p) {
    if (*p != C) *p = '*';
  }

  std::cout << S;
  
  return 0;
}
