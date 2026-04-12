#include <iostream>
#include <string>
#include <vector>
#include <map>

using ll = long long;

int main() {
    int H, W;
    std::cin >> H >> W;
    std::vector<std::vector<char>> a(H, std::vector<char>(W));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            std::cin >> a[h][w];
        }
    }

    for (int w = 0; w < W; w++) {
        bool flag = true;
        for (int h = 0; h < H; h++) {
            if (a[h][w] == '#') {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int h = 0; h < H; h++) {
                a[h][w] = 'N';
            }
        }
    }


    for (int h = 0; h < H; h++) {
        bool flag = true;
        for (int w = 0; w < W; w++) {
            if (a[h][w] == '#') {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int w = 0; w < W; w++) {
                a[h][w] = 'N';
            }
        }
    }


    for (int h = 0; h < H; h++) {
        bool flag = true;
        for (int w = 0; w < W; w++) {
            if (a[h][w] == 'N')continue;
            std::cout << a[h][w];
            flag = false;
        }
        if (!flag)std::cout << std::endl;
    }
}