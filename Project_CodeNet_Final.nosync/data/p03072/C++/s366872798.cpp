#include <iostream>

int main()
{
  int H[100];
  int N;
  std::cin >> N;
  for (int x = 0; x < N; ++x)
    std::cin >> H[x];

  int z = 1;
  int h = H[0];
  for (int x = 1; x < N; ++x)
  {
    if (h <= H[x])
    {
      z++;
    }
    h = H[x] > h ? H[x] : h;
  }
  std::cout << z << std::endl;
}