#include <iostream>
#include <string>

int main() {
  int N, K;
  std::string S;
  std::cin >> N;
  std::cin >> S;
  std::cin >> K;
  
  for (int i=0; i<N; i++) {
    if (S[i] != S[K-1]) S[i] = '*';
  }
  
  std::cout << S << std::endl;
  
  return 0;
}