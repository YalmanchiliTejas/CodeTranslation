#include<bits/stdc++.h>

int main()
{
    int h,w;
    std::cin >> h >> w;
    std::vector<std::string> map(h);
    for(int i = 0; i < h; i++)std::cin >> map[i];
    std::vector<bool> chack2(h);
    for(int i = 0; i < h; i++){
        bool res = true;
        for(int j = 0; j < w; j++)if(map[i][j] == '#')res = false;
        chack2[i] = res;
    }
    std::vector<bool> chack(w);
    for(int i = 0; i < w; i++){
        bool res = true;
        for(int j = 0; j < h; j++)if(map[j][i] == '#')res = false;
        chack[i] = res;
    }

    for(int i = 0; i < h; i++){
        if(chack2[i])continue;
        for(int j = 0; j < w; j++){
            if(chack[j])continue;
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
}