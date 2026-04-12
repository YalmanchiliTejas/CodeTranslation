#include <iostream>

int main() {
    int N;
    std::cin >> N;
    for (int b = 0; b < (1 << N); ++b) {
        std::cout << b << ":";
        for (int i = 0; i < N; ++i) {
            if ((b >> i) & 1) std::cout << " " << i;
        }
        std::cout << std::endl;
    }
}
