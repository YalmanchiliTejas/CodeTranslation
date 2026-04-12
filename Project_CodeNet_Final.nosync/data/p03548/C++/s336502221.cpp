#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int x, y, z;
    std::cin >> x >> y >> z;
    int ans = 0;
    while (x >= ((y + z) * ans) + z) { ans++; }
    std::cout << --ans << std::endl;
    return 0;
}
