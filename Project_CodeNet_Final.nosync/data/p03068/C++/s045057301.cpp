#include <iostream>

int main() {
    int N, K;
    std::string S;
    std::cin >> N >> S >> K;
    
    char c = S[K-1];
    
    for (auto &&i : S) {
        if (i == c)
            std::cout << i;
        else
            std::cout << '*';
    }
    std::cout << std::endl;
}