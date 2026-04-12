#include <iostream>
#include <vector>
#include <algorithm>

using data_map = std::vector<std::vector<char>>;

int main() {
    int h, w;
    std::cin >> h >> w;

    data_map map;
    for (auto y = 0; y < h; ++y) {
        std::vector<char> line(w);
        for (auto& p : line) {
            std::cin >> p;
        }
        if (!std::all_of(std::begin(line), std::end(line),
            [](char c) { return c == '.'; })) {
            map.push_back(line);
        }
    }

    for (auto i = w - 1; 0 <= i ; --i) {
        bool ret = true;
        for (auto& line : map) {
            if (line[i] != '.') {
                ret = false;
                break;
            }
        }
        if (ret) {
            for (auto& line : map) {
                line.erase(std::begin(line) + i);
            }
        }
    }
    for (auto& line : map) {
        for (auto& v : line) {
            std::cout << v;
        }
        std::cout << std::endl;
    }
    return 0;
}