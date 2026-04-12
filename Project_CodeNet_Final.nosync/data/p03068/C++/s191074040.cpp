#include <iostream>
#include <string>

int main() {
    int N, K;
    std::string S;
    std::cin >> N >> S >> K;
    char SK = S[K - 1];
    for (int i = 0; i < N; ++i) {
        if (S[i] != SK) {
            S[i] = '*';
        }
    }
    std::cout << S << "\n";
    return 0;
}
