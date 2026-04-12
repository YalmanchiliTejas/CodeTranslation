#include <iostream>
#include <string>
#include <vector>

int main(void) {
    int h, w;
    
    std::cin >> h >> w;
    
    std::vector< std::vector <int> > a(h, std::vector<int>(w, 0));
    
    for(int i = 0; i < h; i++) {
        std::string line;
        std::cin >> line;
        for(int j = 0; j < w; j++) {
            if(line[j] == '.') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    
    
    std::vector <bool> col(w, false);
    std::vector <bool> row(h, false);
    
    
    for(int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if(a[i][j] == 1){
                row[i] = true;
                col[j] = true;
            }
        }
    }
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) {
            if(row[i] && col[j]){
                if(a[i][j] == 1) std::cout << '#';
                else std::cout << '.';
            }
        }
        std::cout << std::endl;
    }
    return 0;
}

