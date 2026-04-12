#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

int main(int argc, char** argv) {
    int n;
    std::cin >> n;
    int spent = n * 800;
    int discountFactor = n / 15;
    
    std::cout << spent - 200*discountFactor << std::endl;
    return 0;
}
