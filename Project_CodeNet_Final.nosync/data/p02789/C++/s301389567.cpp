#include <iostream>

std::string takahashi_kun(int N, int M)
{
    if (N == M)
        return "Yes";
    return "No";
}

int main()
{
    int N = 0;
    int M = 0;
    std::cin >> N >> M;
    std::cout << takahashi_kun(N, M) << std::endl;
    return 0;
}
