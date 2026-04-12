#include <bitset>
#include <cmath>
#include <iostream>
using ull = unsigned long long;

int main(void) {
    short n;
    std::cin >> n;

    for (int i = 0; i < pow(2, n); ++i) {
        std::cout << i << ':';
        const std::bitset<20> i_bitset(i);
        const std::string i_bitset_string = i_bitset.to_string();

        for (int j = i_bitset_string.size() - 1; j >= 0; --j)
            if (i_bitset_string[j] == '1')
                std::cout << ' ' << i_bitset_string.size() - j - 1;

        std::cout << std::endl;
    }
}
