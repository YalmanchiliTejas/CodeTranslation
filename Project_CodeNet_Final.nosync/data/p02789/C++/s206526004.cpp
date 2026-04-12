#include <cstdint>
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <string>



int main()
{
    int32_t n,m;

    std::cin >> n >> m;

    if ( n == m ) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}
