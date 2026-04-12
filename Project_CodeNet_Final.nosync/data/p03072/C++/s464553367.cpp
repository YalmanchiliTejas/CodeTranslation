#include <bits/stdc++.h>

int main()
{
  int N;
  std::cin >> N;
  
  int maxH = 0;
  int count = 0;
  for (int i = 0; i < N; i++)
  {
    int h;
    std::cin >> h;
    
    if (h >= maxH)
    {
      count++;
    } 
    
    maxH = h > maxH ? h : maxH;
  }
  
  std::cout << count << std::endl;
  return 0;
}
