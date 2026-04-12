#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

const int mod = 1e9 + 7;

int main()
{
    int x, y, z;
    std::cin >> x >> y >> z;

    std::cout << (x - z) / (y + z) << std::endl;
}
