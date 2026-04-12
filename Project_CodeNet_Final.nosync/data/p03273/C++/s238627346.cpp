#include <iostream>
using namespace std;

int main(void){
    int H, W;
    char g[102][102];
    
    cin >> H >> W;
    
    for(int i = 0; i < H; i++){
        cin >> g[i];
    }
    
    for(int j = 0; j < W; j++){
        int i = 0;
        int delete_flag = 1;
        while(g[i][j]){
            if(g[i][j] == '#'){
                delete_flag = 0;
                break;
            }
            i++;
        }
        if(delete_flag == 1){
            W--;
            for(int k = j; k < W; k++){
                for(i = 0; i < H; i++){
                    g[i][k] = g[i][k + 1];
                }
            }
            j--;
        }
    }
    
    
    for(int i = 0; i < H; i++){
        int delete_flag = 1;
        for(int j = 0; j < W; j++){
            if(g[i][j] == '#'){
                delete_flag = 0;
                break;
            }
        }
        if(delete_flag == 0){
            for(int j = 0; j < W; j++){
                cout << g[i][j];
            }
            cout << endl;
        }
    }
    
    return 0;
}
