#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> a(h);
    for (int i = 0; i < h; i++) {
        std::cin >> a[i];
    }

    int y = 0, x = 0;
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w - 1; j++) {
            if (a[i + 1][j] == '#' && a[i][j + 1] == '#') {
                std::cout << "Impossible" << std::endl;
                return 0;
            }
        }
    }

    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (a[i - 1][j] == '#' && a[i][j - 1] == '#') {
                std::cout << "Impossible" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "Possible" << std::endl;
}
