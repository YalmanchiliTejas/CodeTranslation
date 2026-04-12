#include <iostream>

#define INF 1e9 + 7;

int main(){
    int a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;

//    1
//    x * a + y * b;
//
//    2
//    int z = std::min(x, y);
//    (x - z) * a + (y - z) * b + z * c;
//
//    3
//    std::max(x, y) * c;

    int ans = (int)INF; 
    for(int i = 0; i <= std::max(x, y) * 2; i += 2){
        ans = std::min(ans, std::max(0, x - i / 2) * a + std::max(0, y - i / 2) * b + i * c);
    }

    std::cout << ans << std::endl;

    return 0;
}