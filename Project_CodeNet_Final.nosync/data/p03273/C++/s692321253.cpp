#include<iostream>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;

    char a[H][W];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> a[i][j];
        }
    }

    /* for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << a[i][j];
        }
        cout << endl;
    }*/

    int cou = 0;
    int frag_y[H];
    for(int i = 0; i < H; i++){
        frag_y[i] = 0;
    }
    int frag_x[W];
    for(int i = 0; i < W; i++){
        frag_x[i] = 0;
    }

    for(int i = 0; i < H; i++){
        cou = 0;
        for(int j = 0; j < W; j++){
            if(a[i][j] == '.'){
                cou++;
            }
        }
        if(cou == W){
            frag_y[i] = 1;
        }
    }

    for(int i = 0; i < W; i++){
        cou = 0;
        for(int j = 0; j < H; j++){
            if(a[j][i] == '.'){
                cou++;
            }
        }
        if(cou == H){
            frag_x[i] = 1;
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(frag_y[i] == 0 && frag_x[j] == 0){
                cout << a[i][j];
            }else{
                continue;
            }
        }

        if(frag_y[i] == 0){
            cout << endl;
        }
    }
}