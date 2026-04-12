#include <iostream>

int main(){
   std::string input;
   std::cin >> input ;
   char test;
   if (input[0] != input[1]) {
      std::cout << "Yes" << std::endl;
      return 0;
   }
   if (input[1] != input[2]) {
      std::cout << "Yes" << std::endl;
      return 0;
   }
   if (input[0] != input[2]) {
      std::cout << "Yes3" << std::endl;
      return 0;
   }

   std::cout << "No" << std::endl;
   return 0;
}