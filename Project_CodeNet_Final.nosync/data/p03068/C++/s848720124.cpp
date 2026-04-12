#include <iostream>
#include <string>

int main()
{
  int N, K;
  std::string S;

  std::cin >> N >> S >> K;

  int wc = 0, bc = 0;
  for (int i = 0; i < S.size(); i++)
  {
    if (S[i] != S[K - 1])
    {
      S[i] = '*';
    }
  }

  std::cout << S << std::endl;
}
