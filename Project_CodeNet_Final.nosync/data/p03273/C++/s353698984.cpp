#include <iostream>
#include <string>
#include <vector>

int main()
{
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> b(H); 
    for (int i = 0; i < H; i++) {
        std::cin >> b[i];
        if (b[i].find('#') == std::string::npos) {
            b[i] = std::string(W, '*');
        }
    }

    for (int i = 0; i < W; i++) {
        bool del = true;
        for (int j = 0; j < H; j++) {
           if (b[j][i] == '#') {
               del = false;
               break;
           } 
        }

        if (del) {
            for (int j = 0; j < H; j++) {
                b[j][i] = '*';
            }   
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (b[i][j] != '*') {
                std::cout << b[i][j];
            }
        }
        std::cout << std::endl;
    }

    return 0;
}