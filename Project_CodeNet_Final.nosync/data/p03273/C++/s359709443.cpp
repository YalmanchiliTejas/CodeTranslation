#include <iostream>
#include <vector>
using namespace std;
int main(void){
    // Your code here!
    int h, w;
    char a[100][100];
    std::vector<int> idx;
    
    std::cin >> h >> w;
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            std::cin >> a[i][j];
        }
    }
    
    int delCount = 0;
    for(int i = 0; i < h; i++){
        int dotCount = 0;
        for(int j = 0; j < w; j++){
            if(a[i][j] == '.') dotCount++;
        }
        if(dotCount == w){
            a[i][0] = '*';
        }
        //std::cout << dotCount << std::endl;
    }
    
    for(int i = 0; i < w; i++){
        int dotCount = 0;
        for(int j = 0; j < h; j++){
            //std::cout << a[j][i];
            if(a[j][i] == '.' || a[j][i] == '*') dotCount++;
        }
        if(dotCount == h){
            a[0][i] = '*';
            idx.push_back(i);
        }
        //std::cout << std::endl;
        //std::cout << dotCount << std::endl;
    }
    
    //std::cout << std::endl;
    
    for(int i = 0; i < h; i++){
            int flag = 1;
        for(int j = 0; j < w; j++){
            int f = 0;
            for(int k = 0; k < idx.size(); k++){
                if(idx[k] == j){
                    f = 1;
                }
            }
            if(f){
                continue;
            }
            
            if(a[i][0] == '*') {
                flag = 0;
                continue;
            }
            std::cout << a[i][j];
        }
        if(flag){
            std::cout << std::endl;
        }
    }
    
    /*
    for(int i = 0; i < idx.size(); i++){
        std::cout << idx[i] << std::endl;
    }
    */
    
    return 0;
}
