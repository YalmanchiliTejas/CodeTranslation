#include <iostream>
#include <cstdint>
int main()
{
    std::uint_fast16_t n, x;
    std::cin >> n >> x;
    std::cout << ((n == x) ? "Yes" : "No") << std::endl;
}