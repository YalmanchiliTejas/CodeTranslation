#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int h, w;
    std::cin >> h >> w;

    int count = 0;
    for (int i = 0; i < h; i++) {
        std::string temp;
        std::cin >> temp;

        count += std::count(temp.begin(), temp.end(), '#');
    }

    if (count == h + w - 1) {
        std::cout << "Possible" << std::endl;
    } else {
        std::cout << "Impossible" << std::endl;
    }
}
