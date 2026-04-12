#include <bits/stdc++.h>

int main() {
    std::string r, g, b;
    std::cin >> r >> g >> b;

    int num = std::atoi((r+g+b).c_str());
    if(num % 4 == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}