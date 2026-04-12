#include <iostream>
short n, h, a, m;
signed main()
{
    std::cin >> n;
    while (n--)
    {
        std::cin >> h;
        if (h >= m) a++, m = h;
    }
    std::cout << a;
}
