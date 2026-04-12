#include<bits/stdc++.h>

int main(){
    int h, w;
    std::cin >> h >> w;
    
    std::vector<std::string> a;
    for(int i = 0; i < h; i++){
        std::string s;
        std::cin >> s;
        a.push_back(s);
    }
    
    for(int y = h - 1; y >= 0; y--){
        bool flag = true;
        for(int x = 0; x < w; x++){
            if(a[y][x] == '#'){
                flag = false;
                break;
            }
        }
        if(flag){
            a.erase(a.begin() + y);
            h--;
        }
    }
    
    for(int x = w - 1; x >= 0; x--){
        bool flag = true;
        for(int y = 0; y < h; y++){
            if(a[y][x] == '#'){
                flag = false;
                break;
            }
        }
        if(flag){
            for(int y = 0; y < h; y++){
                a[y].erase(x, 1);
            }
            w--;
        }
    }
    
    for(std::string s : a){
        std::cout << s << std::endl;
    }
    return 0;
}
