#ifdef __GNUC__
#include <bits/stdc++.h>
#endif // __GNUC__

int main() {
    std::cin.tie(nullptr); std::ios::sync_with_stdio(false);

    int N;
    std::string S;
    int K;
    std::cin >> N >> S >> K;
    for (auto& i : S) {
        if (i != S[K - 1])i = '*';
    }
    std::cout << S << std::endl;
}   