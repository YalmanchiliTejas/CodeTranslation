#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

int main() {
    int h, w;

    std::cin >> h >> w;

    std::vector<std::vector<char> > v(h, std::vector<char>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> v[i][j];
        }
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 && j == 0) continue;
            if (v[i][j] == '#') {
                bool in = false, out = false;
                if (!((i > 0 && v[i - 1][j] == '#') && (j > 0 && v[i][j - 1] == '#')) &&
                    !((i > 0 && v[i - 1][j] == '.') && (j > 0 && v[i][j - 1] == '.'))) in = true;
                if (!((i + 1 < h && v[i + 1][j] == '#') && (j + 1 < w && v[i][j + 1] == '#')) &&
                    !((i + 1 < h && v[i + 1][j] == '.') && (j + 1 < w && v[i][j + 1] == '.'))) out = true;

                if (!(in && out)) {
                    std::cout << "Impossible" << std::endl;
                    return 0;
                }
            }
        }
    }

    std::cout << "Possible" << std::endl;

    return 0;
}