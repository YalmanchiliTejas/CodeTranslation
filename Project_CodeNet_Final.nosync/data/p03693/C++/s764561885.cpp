#include <iostream>

int main(void)
{
    int a, b, c;
    std::cin >> a >> b >> c;
    int total = a * 100 + b * 10 + c;
    bool flag = (total % 4) == 0;
    std::cout << (flag ? "YES" : "NO") << std::endl;
    return 0;
}
