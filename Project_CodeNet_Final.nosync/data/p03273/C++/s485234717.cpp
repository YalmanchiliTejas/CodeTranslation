#include <bits/stdc++.h>

int main(int argc, char *argv[])
{
    int H, W;
    std::cin >> H >> W;
    std::vector<std::string> vec(H); 

    for (int i = 0; i < H; i++) {
        std::cin >> vec[i];
    }

    std::vector<bool> row(H, false);
    std::vector<bool> col(W, false);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (vec[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        if (row[i]) {
            for (int j = 0; j < W; j++) {
                if (col[j]) {
                    std::cout << vec[i][j];
                }
            }
            std::cout << std::endl;
        }
    }

    return 0;
}