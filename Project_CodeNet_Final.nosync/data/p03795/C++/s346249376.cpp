#include <iostream>
#include <vector>

int main(void){
    int n;
    std::cin >> n;
    int x = n*800;
    int y = n/15 * 200;
    std::cout << x - y;
    return 0;
}
