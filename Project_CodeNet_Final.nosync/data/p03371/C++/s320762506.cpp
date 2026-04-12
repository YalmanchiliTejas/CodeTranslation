#include <iostream>
#include <algorithm>

int main() {
    int a,b,c,x,y,t1,t2,t3;
    
    std::cin >> a >> b >> c >> x >> y;

    t3 = a * x + b * y;
    if(x>y){
        t1 = c * 2 * y + a * (x - y);
        t2 = c * 2 * x;
    } else {
        t1 = c * 2 * x + b * (y - x);
        t2 = c * 2 * y;
    }

    std::cout << std::min(std::min(t1, t2), t3) << std::endl;
}