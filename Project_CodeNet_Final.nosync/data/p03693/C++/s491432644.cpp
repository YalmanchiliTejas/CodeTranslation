#include <iostream>

int main(int argc, char **argv){
    int r, g, b;
    std::cin >> r;
    std::cin >> g;
    std::cin >> b;

    int value = r * 100 + g * 10 + b;

    if(value % 4 == 0){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
    
}
