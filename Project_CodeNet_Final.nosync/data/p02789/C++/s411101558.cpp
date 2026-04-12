#include <iostream>

int n;
int m;

int main() {
    std::cin >> n >> m;
    if (n==m) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }
}