#include <iostream>

using namespace std;

int main(){
    int H,W;
    cin >> H >> W;

    char grid[H][W];

    for(int i = 0; i < H; i++){
        for(int n = 0; n < W; n++){
            cin >> grid[i][n];
        }
    }

    bool check = false;

    do{
        check = false;
        
        //横のチェック
        for(int i = 0; i < H; i++){
            bool hCheck = false;
            for(int n = 0; n < W; n++){
                if(grid[i][n] == '#'){
                    hCheck = true;
                    break;
                }
            }
            if(!hCheck){
                for(int x = i; x < H-1; x++){
                    for(int n = 0; n < W; n++){
                        grid[x][n] = grid[x+1][n];
                    }
                }
                H--;
                check = true;
                break;
            }
        }
        if(check) continue;
        
        //縦のチェック
        for(int i = 0; i < W; i++){
            bool wCheck = false;
            for(int n = 0; n < H; n++){
                if(grid[n][i] == '#'){
                    wCheck = true;
                    break;
                }
            }
            if(!wCheck){
                for(int x = i; x < W-1; x++){
                    for(int n = 0; n < H; n++){
                        grid[n][x] = grid[n][x+1];
                    }
                }
                W--;
                check = true;
                break;
            }
        }
        
    }while(check);

    for(int i = 0; i < H; i++){
        for(int n = 0; n < W; n++){
            cout << grid[i][n];
        }
        cout << endl;
    }

    return 0;
}