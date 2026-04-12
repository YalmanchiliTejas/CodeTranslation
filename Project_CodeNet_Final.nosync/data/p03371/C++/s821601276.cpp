#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
int main()
{
    int A, B, C, X, Y;
    std::cin >> A >> B >> C >> X >> Y;
    
    auto _1 = X*A + Y*B;
    auto _2 = std::min(X,Y) * C * 2 + ( X > Y ? (X-Y)*A : (Y-X)*B );
    auto _3 = std::max(X,Y) * C * 2;
    
    std::cout << std::min({_1,_2,_3}) << std::endl;
}