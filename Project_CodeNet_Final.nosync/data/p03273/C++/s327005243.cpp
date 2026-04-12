#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    char grid[105][105];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> grid[i][j];
        }
    }
    
    for(int i = 0; i < h; i++){
        bool flag = true;
        int st;
        for(int j = 0; j < w; j++){
            if(grid[i][j] != '.'){
                flag = false;
            }
            if(flag == true && j == w - 1){
                st = i;
            }
        }
        if(flag){
            for(int k = st; k < h-1; k++){
                for(int i = 0; i < w; i++){
                    grid[k][i] = grid[k+1][i];
                }
            }
            h = h - 1;
            i--;
        }
    }

    for(int i = 0; i < w; i++){
        bool flag = true;
        int st;
        for(int j = 0; j < h; j++){
            if(grid[j][i] != '.'){
                flag = false;
            }
            if(flag == true && j == h - 1){
                st = i;
            }
        }
        if(flag){
            for(int k = st; k < w-1; k++){
                for(int i = 0; i < h; i++){
                    grid[i][k] = grid[i][k+1];
                }
            }
            w = w - 1;
            i--;
        }
    }

    //print
    for(int i = 0 ; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }

}