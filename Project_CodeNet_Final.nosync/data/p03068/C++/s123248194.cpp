#include <string>
#include <cstdlib>
#include <iostream>


int main(int argc, const char *argv[])
{
    int N;
    std::string S;
    int K;

    std::cin >> N >> S >> K;
    char c = S[K - 1];
    for (int i = 0; i < N; i++) if (S[i] != c) S[i] = '*';

    std::cout << S << std::endl;
}