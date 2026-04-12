#include <iostream>
#include <algorithm>

int main(){
   long long int A, B, C, X, Y;
   std::cin >> A >> B >> C >> X >> Y;
   long long int c;
   if (A+B >= 2*C){
      if (X >= Y){
         c = std::min(2*X*C, 2*C*Y+(X-Y)*A);
      } else{
         c = std::min(2*Y*C, 2*C*X+(Y-X)*B);
      }
   } else{
      c = A*X+B*Y;
   }
   std::cout << c << std::endl;

}
