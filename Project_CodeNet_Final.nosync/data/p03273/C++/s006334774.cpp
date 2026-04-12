#include <iostream>

#define N_MAX 100

using namespace std;

char grid[N_MAX][N_MAX];
int row_all_white[N_MAX];
int col_all_white[N_MAX];

int main(){
    int H, W;
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < H; i++){
        row_all_white[i] = 1;
        for(int j = 0; j < W; j++){
            if(grid[i][j] == '#'){
                row_all_white[i] = 0;
                break;
            }
        }
    }

    for(int i = 0; i < W; i++){
        col_all_white[i] = 1;
        for(int j = 0; j < H; j++){
            if(grid[j][i] == '#'){
                col_all_white[i] = 0;
                break;
            }
        }
    }

    for(int i = 0; i < H; i++){
        if(row_all_white[i] == 0){
            for(int j = 0; j < W; j++){
                if(col_all_white[j] == 0){
                    cout << grid[i][j];
                }
            }
            cout << '\n';
        }
    }
    return 0;

}