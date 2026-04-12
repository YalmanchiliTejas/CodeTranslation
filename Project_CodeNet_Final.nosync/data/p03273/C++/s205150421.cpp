/*
  Contest 107
  B - Grid Compression
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

inline void print(const std::vector<std::string>& grid, const std::vector<bool>& cols) {
    for (std::size_t r = 0; r < grid.size(); ++r) {
        for (std::size_t c = 0; c < grid[r].size(); ++c)
            if (cols[c])
                std::cout << grid[r][c];
        std::cout << std::endl;
    }
}

inline void check_cols(const std::vector<std::string>& grid, std::vector<bool>& cols) {
    for (std::size_t c = 0; c < grid[0].size(); ++c) {
        for (std::size_t r = 0; r < grid.size(); ++r)
            if (grid[r][c] == '#')
                cols[c] = true;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int r = 0, c = 0;
    std::cin >> r >> c;
    std::cin.ignore();

    std::vector<std::string> grid;
    while (r--) {
        std::string s;
        std::getline(std::cin, s);
        if (s.find('#') != std::string::npos)
            grid.emplace_back(s);
    }
    std::vector<bool> cols(c, false);
    check_cols(grid, cols);
    print(grid, cols);

    return 0;
}
