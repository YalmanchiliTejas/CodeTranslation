#include<iostream>
#include<vector>

int main(){
    int H, W;
    std::cin >> H >> W;
    std::vector<bool> isEmptyRow(H, true), isEmptyColumn(W, true);
    std::vector<std::vector<char>> pix(H, std::vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            std::cin >> pix[i][j];
            if(pix[i][j] == '#'){
                isEmptyRow[i] = false;
                isEmptyColumn[j] = false;
            }
        }
    }

    for(int i = 0; i < H; i++){
        if(isEmptyRow[i]) continue;
        for(int j = 0; j < W; j++){
            if(isEmptyColumn[j]) continue;
            std::cout << pix[i][j];
        }
        std::cout << std::endl;
    }



    return 0;
}
