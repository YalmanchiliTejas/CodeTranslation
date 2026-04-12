#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string S;
    int N, K;
    char ch;
    std::cin >> N >> S >> K;
    ch = S[K - 1];
    for (char c : S)
    {
        if (c != ch) { std::cout << '*'; }
        else
        {
            std::cout << ch;
        }
    }
    std::cout << std::endl;

    return 0;
}
