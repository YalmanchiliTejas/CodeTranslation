#include <iostream>

using namespace std;

int main(){
    int H,W;
    cin >> H >> W;

    char grid[H][W];
    bool len[W],row[H];
    for(int i = 0; i < H; i++) row[i] = false;
    for(int i = 0; i < W; i++) len[i] = false;
    
    for(int i = 0; i < H; i++){
        for(int n = 0; n < W; n++){
            cin >> grid[i][n];
            if(grid[i][n] == '#'){
                row[i] = true;
                len[n] = true;
            }
        }
    }


    for(int i = 0; i < H; i++){
        for(int n = 0; n < W; n++){
            if(row[i] && len[n]){
                cout << grid[i][n];
            }
        }
        if(row[i]) 
            cout << endl;
    }
    return 0;
}