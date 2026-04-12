#include<iostream>
    using namespace std;
    int main()
    {
      int n;
      std::cin >> n;
      int x,y;

      x = n*800;
      y = (n/15)*200;

      std::cout << x-y << '\n';
        return 0;
      }
