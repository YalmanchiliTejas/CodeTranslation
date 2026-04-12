#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(void){
    int a,b,c,x,y;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> x;
    std::cin >> y;
    if(a + b > 2 * c){
        if(x > y){
            if(a > 2 * c){
                std::cout << x * 2 * c << std::endl;
            } else {
                std::cout << (y * 2 * c) + ((x - y) * a) << std::endl;
            }
        } else {
            if(b > 2 * c){
                std::cout << y * 2 * c << std::endl;
            } else {
                std::cout << (x * 2 * c) + ((y - x) * b) << std::endl;
            }
        }
    } else {
        std::cout << (a * x) + (b * y) << std::endl;
    }
}