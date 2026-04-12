#include <iostream>

#define INF 1e9 + 7;

int main(){
    int a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;

    int ans = (int)INF; 
    for(int i = 0; i <= std::max(x, y) * 2; i += 2){ // alter the number of mixed pizzas
        ans = std::min(ans, std::max(0, x - i / 2) * a + std::max(0, y - i / 2) * b + i * c);
    }

    std::cout << ans << std::endl;

    return 0;
}