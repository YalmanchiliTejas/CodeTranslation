#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    if (S[0] == S[1] && S[1] == S[2]) {
        std::printf("No\n");
    } else {
        std::printf("Yes\n");
    }

    return 0;
}
