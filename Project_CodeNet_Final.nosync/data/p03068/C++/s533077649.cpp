#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
typedef long long LL;

int main() {
  int N; std::cin >> N;
  std::string S; std::cin >> S;
  int K; std::cin >> K;

  char t = S[K-1];
  for (char& c : S) {
    if (c != t) c = '*';
  }

  std::cout << S << std::endl;
}
