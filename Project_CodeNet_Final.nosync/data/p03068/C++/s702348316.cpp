#include <iostream>

int main() {
    int n, k;
    char x;
    std::string s;
    std::cin >> n >> s >> k;
    x = s[k-1];
    for (char c : s) {
        if (c != x) std::cout << '*';
        else std::cout << c;
    }
    std::cout << '\n';
    return 0;
}