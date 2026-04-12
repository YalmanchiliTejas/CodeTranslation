#include <iostream>

int main()
{
  size_t N;
  std::cin >> N;
  int H[N];
  for(size_t i = 0;
      i < N;
      ++i)
    {
      std::cin >> H[i];
    }

  int ret = 1;

  for(size_t i = 1;
      i < N;
      ++i)
    {
      bool high = true;
      for(size_t j = 0;
          j < i;
          ++j)
        {
          if(H[i] < H[j])
            {
              high = false;
              break;
            }
        }
      if(high)
        {
          ++ret;
        }
    }
  std::cout << ret << std::endl;
  return 0;
}
