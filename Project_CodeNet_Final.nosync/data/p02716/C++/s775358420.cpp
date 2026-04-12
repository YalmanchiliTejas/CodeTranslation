#include <iostream>
#include <limits>
#include <numeric>

constexpr long small_enough = -2000000001;

int main()
{
    int N;
    std::cin >> N;

    long skip0 = 0;
    auto skip1 = small_enough;
    auto skip2 = small_enough;

    for (auto i = 1; i <= N; i++) {
        long input;
        std::cin >> input;

        if (i % 2 == 0) {
            skip2 = std::max(skip1, skip2);
            skip1 += input;

        } else {
            skip2 += input;
            skip1 = std::max(skip0, skip1);
            skip0 += input;
        }
    }

    std::cout << std::max(skip1, (N % 2 == 0 ? skip0 : skip2)) << std::endl;

    return 0;
}
