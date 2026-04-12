#include <cstdio>
#include <cstdint>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

int main()
{
    int H, W;

    std::cin >> H >> W;

    std::unordered_set<int> skiprows;
    std::unordered_set<int> skipcols;

    char A[H][W];

    for (int i = 0; i < H; ++i) {
        bool allwhite = true;
        for (int j = 0; j < W; ++j) {
            std::cin >> A[i][j];
            if (allwhite == true && A[i][j] == '#') {
                allwhite = false;
            }
        }

        if (allwhite == true) {
            skiprows.insert(i);
        }
    }

    for (int j = 0; j < W; ++j) {
        bool allwhite = true;
        for (int i = 0; i < H; ++i) {
            if (allwhite == true && A[i][j] == '#') {
                allwhite = false;
                break;
            }
        }

        if (allwhite == true) {
            skipcols.insert(j);
        }
    }

    for (int i = 0; i < H; ++i) {
        if (skiprows.count(i) != 0) {
            continue;
        }
        for (int j = 0; j < W; ++j) {
            if (skipcols.count(j) != 0) {
                continue;
            }

            std::printf("%c", A[i][j]);
        }

        std::printf("\n");
    }

    return 0;
}