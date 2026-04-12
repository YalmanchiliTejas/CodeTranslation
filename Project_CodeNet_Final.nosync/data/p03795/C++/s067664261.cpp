#include <iostream>

int main() {
    int N, given=0;
    std::cin >> N;
    given = 200 * ( N / 15 );
    std::cout << 800 * N - given << std::endl;
    return 0;
}