#include <iostream>

int main(){
   int A, B, C, X, Y;
   std::cin >> A >> B >> C >> X >> Y;

   int AB = std::min(A+B, C*2);
   int ans = 0;
   int x = std::min(X, Y);
   int y = x;
   ans += x*AB;
   ans += std::min((X-x)*A+(Y-y)*B, std::max((X-x),(Y-y))*AB);

   std::cout << ans << std::endl;
   return 0;

}
