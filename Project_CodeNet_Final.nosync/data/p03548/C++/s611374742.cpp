#include <iostream>
#include <algorithm>

int main() {
    int X, Y, Z;
    std::cin >> X >> Y >> Z;
    
    int ans = 0;
    
    while (X >= (Y+2*Z)) {
        ans++;
        X -= (Y + Z);
    }
    
    std::cout << ans << std::endl;
}