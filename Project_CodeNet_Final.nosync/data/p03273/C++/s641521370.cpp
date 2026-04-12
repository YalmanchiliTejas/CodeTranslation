#include <iostream>
#include <vector>

int main() {
    int H, W; std::cin >> H >> W;
    std::vector<std::vector<char>> m(H, std::vector<char>(W));
    for (int i =0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> m[i][j];
        }
    }

    std::vector<bool> h(H, false);
    for (int i = 0; i < H; i++) {
        bool all = true;
        for (int j = 0; j < W; j++) {
            if (m[i][j] == '#') {
                all =false;
                break;
            }
        }
        if (all) {
            h[i] = true;
        }
    }
    std::vector<bool> w(W, false);
    for (int j = 0; j < W; j++) {
        bool all = true;
        for (int i = 0; i < H; i++) {
            if (m[i][j] == '#') {
                all = false;
                break;
            }
        }
        if (all) {
            w[j] = true;
        }
    }

    for (int i =0; i < H; i++) {
        if (h[i]) {
            continue;
        }
        for (int j = 0; j < W; j++) {
            if (w[j]) {
                continue;
            }
            std::cout << m[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}