#include <iostream>

int main(){
   int r, g, b;
   std::cin >> r >> g >> b;

   int n = 100*r + 10*g + b;
   if(n%4==0) std::cout << "YES" << std::endl;
   else std::cout << "NO" << std::endl;
   return 0;
}
