#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

int main()
{
    int64_t N;

    std::cin >> N;
    std::vector<int64_t> A;
    std::vector<int64_t> B;
    for (int64_t n = 0; n < N; ++n)
    {
        int64_t a;
        std::cin >> a;
        A.emplace_back(a);
    }

    int64_t v = 0;
    for (int64_t n = N - 1; n >= 1; --n)
    {
        v += A[n];
        v = v % 1000000007ull;
        B.emplace_back(v);
    }
    
    std::reverse(B.begin(), B.end());

    v = 0;
    for (int64_t n = 0; n < N - 1; ++n)
    {
        v += A[n] * B[n];
        v = v % 1000000007ull;
    }
    std::cout << v << std::endl;
    
    return 0;
}

