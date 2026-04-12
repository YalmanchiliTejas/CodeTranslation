#include <iostream>
#include <vector>
#include <string>

int main()
{
    int x, y, z;
    std::cin >> x >> y >> z;

    int i = 0;
    int f = y * i + z * (i + 1);
    while (f <= x)
    {
        i++;
        f = y * i + z * (i + 1);
       
    }

    std::cout << i - 1 << "\n";
}