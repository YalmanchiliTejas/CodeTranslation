#include <iostream>

int main(void) {
    int N, K;
    char *S;
    std::cin >> N;
    S = new char[N+1];

    std::cin >> S >> K;

    for(int i=0; i<N; i++) {
        if(S[i] != S[K-1]) S[i] = '*';
    }

    std::cout << S << "\n";
    return 0;
}
