#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<vector>

int main() {

   int A, B, C, X, Y;
   std::cin >> A >> B >> C >> X >> Y;
   double coe = C - A / 2 - B / 2;
  
   int ans = A * X + B * Y;
   int max = X;
   if (max < Y) max = Y;
   int Nc = 2 * max;
   for (int i = 1; i <= Nc; i++) {
      int Na = std::max(0, X - i / 2);
      int Nb = std::max(0, Y - i / 2);
      int tmp = Na * A + Nb * B + i * C;
      if (ans > tmp) ans = tmp;
   }
   
   std::cout << ans<< std::endl;
   return 0;
}
