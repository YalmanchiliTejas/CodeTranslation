#include <iostream>

int r, g, b;

int main(void){
    std::cin >> r >> g >> b;
    int res = r*100 + g*10 + b;
    if(res%4 == 0){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
}
