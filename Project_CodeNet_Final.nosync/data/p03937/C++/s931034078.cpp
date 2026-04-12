#include <iostream>

int main() {
    int H, W, s = 1;
    std::cin >> H >> W;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char t;
            std::cin >> t;
            if (t == '#') s++;
        }
    }

    std::cout << (s == H + W ? "Possible" : "Impossible") << std::endl;
}
