#include <iostream>
#include <vector>

int main()
{
    unsigned int h, w;
    std::cin >> h >> w;
    char c;
    unsigned int counter = 0;
    while(std::cin >> c)
    {
        counter += (c == '#');
    }
    std::cout << (counter == h + w - 1 ? "Possible" : "Impossible")
              << std::endl;
}
