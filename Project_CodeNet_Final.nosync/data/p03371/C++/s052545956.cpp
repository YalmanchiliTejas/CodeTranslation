#include <iostream>
#include <vector>

int main()
{
  int a, b, c, x, y;
  std::cin >> a >>  b >> c >> x >> y;
  if(a+b < c*2)
  {
    std::cout << a*x+b*y << std::endl;
    return 0;
  }

  int cost = 0;
  int num_share = std::min(x, y);
  cost += num_share*c*2;
  if(x-y>0)
  {
    cost += std::min((x-y)*a, (x-y)*c*2);
  }
  else
  {
    cost += std::min((y-x)*b, (y-x)*c*2);
  }
  std::cout << cost << std::endl;
  // int num_para = std::abs(x-y);
}
