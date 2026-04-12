#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
  int N, M;
  std::cin >> N >> M;
  std::string result = (N == M) ? "Yes" : "No";
  std::cout << result;
}
