#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    int a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;

    int min = 2147483647;
    min = std::min(min, a * x + b * y);
    min = std::min(min, std::max(x, y) * 2 * c);

    int buf;
    if(x > y){
        buf = (x - y) * a;
    }
    if(y > x){
        buf = (y - x) * b;
    }

    std::cout << std::min(min, std::min(x, y) * 2 * c + buf) << std::endl;;
    
    return 0;
}