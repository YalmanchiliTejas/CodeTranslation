#include <iostream>

int x, y, z;

int main() {
    std::cin >> x >> y >> z;
    int res=x/(y+z);
    if (x%(y+z) < z) --res;

    std::cout << res << std::endl;
    return 0;
}
