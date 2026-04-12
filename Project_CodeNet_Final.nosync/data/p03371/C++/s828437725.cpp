#include <iostream>
#include <assert.h>
#include <algorithm>

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int64_t A,B,C,X,Y;
    std::cin >> A >> B >> C >> X >> Y;
    constexpr int64_t INF = 1LL << 60;
    int64_t min_sum = INF;

    //Case1. A = X, B = Y, C = 0
    min_sum = std::min(min_sum, A * X + B * Y);
    //Case2. X >= Y, C = 2Y, A = X - Y
    //Case3. X >= Y, C = 2X
    if(X >= Y){
        min_sum = std::min(min_sum, C * 2 * Y + A * (X - Y));
        min_sum = std::min(min_sum, C * 2 * X);
    }
    //Case4. X <= Y, C = 2X, B = Y - X
    //Case5. X <= Y, C = 2Y
    else{
        min_sum = std::min(min_sum, C * 2 * X + B * (Y - X));
        min_sum = std::min(min_sum, C * 2 * Y);
    }

    std::cout << min_sum << std::endl;
    return 0;

}
