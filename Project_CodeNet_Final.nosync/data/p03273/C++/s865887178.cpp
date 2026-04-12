#include <iostream>
#include <algorithm>
#include <vector>

int main(void){
    int H, W;
    std::cin >> H >> W;
    std::vector<std::vector<char>> grid(H, std::vector<char>(W));
    std::vector<int> ignore_col, ignore_raw;
    for (int i = 0; i < H; ++i){
        bool flg = true;
        std::string S;
        std::cin >> S;
        for (int j = 0; j < W; ++j){
            grid[i][j] = S.at(j);
            if (S.at(j) == '#') flg = false;
        }
        if (flg) ignore_raw.push_back(i);
    }

    for (int i = 0; i < W; ++i){
        bool flg = true;
        for (int j = 0; j < H; ++j){
            if (grid[j][i] == '#') flg = false;
        }
        if (flg) ignore_col.push_back(i);
    }

    for (int i = 0; i < H; ++i){
        bool flg = false;
        for (int j = 0; j < W; ++j){
            if (std::find(ignore_raw.begin(), ignore_raw.end(), i) == ignore_raw.end()){
                if (std::find(ignore_col.begin(), ignore_col.end(), j) == ignore_col.end()) {
                    std::cout << grid[i][j];
                    flg = true;
                }
            }
        }
        if (flg) std::cout << std::endl;
    }

    return 0;
}
