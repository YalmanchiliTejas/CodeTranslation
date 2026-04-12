#include <iostream>


int main(){

    int N;
    std::cin >> N;

    int x = N*800;
    int y = N/15 * 200;
    std::cout << x-y;
    return 0;
}

