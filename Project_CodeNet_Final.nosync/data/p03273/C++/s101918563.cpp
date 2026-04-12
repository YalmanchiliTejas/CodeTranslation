#include<iostream>
#include<vector>

int main(){
    
    int h, w;

    std::cin >> h >> w;

    std::vector<std::vector<char>> a(h, std::vector<char>(w));

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            std::cin >> a[i][j];
        }
    }

    std::vector<bool> flag_h(h, false);
    std::vector<bool> flag_w(w, false);

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#'){
                flag_h[i] = true;
                flag_w[j] = true;
            }
        }
    }

    for(int i = 0; i < h; i++){
        if(flag_h[i] == true){
            for(int j = 0; j < w; j++){
                if(flag_w[j] == true){
                    std::cout << a[i][j];
                }
            }std::cout << std::endl;
        }
    }
    
    return 0;
}
