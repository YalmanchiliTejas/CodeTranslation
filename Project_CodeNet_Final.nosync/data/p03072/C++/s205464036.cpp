#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int hotels[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> hotels[i];
    }
    int c = 0;
    int height = hotels[0];
    for (int i = 1; i < n; ++i) {
        if (hotels[i] >= height) {
            c++;
            height = hotels[i];
        }
    }
    std::cout << c + 1 << std::endl;
    
}
