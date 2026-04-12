#include <cstdio>
#include <iostream>
#include <string>

int main()
{
    int N, K;
    std::string S;
    scanf("%d", &N);
    std::cin >> S;
    scanf("%d", &K);

    auto a = S[K - 1];

    for (int i = 0; i < N; i++) {
        if (S[i] != a) {
            S[i] = '*';
        }
    }
    std::cout << S << "\n";


    return 0;
}
