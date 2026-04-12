#include<bits/stdc++.h>

using namespace std;

int main(){
    int H, W; cin >> H >> W;
    bool x[H], y[W];
    fill(x, x + W, false);
    fill(y, y + H, false);
    char c[H][W];
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < H; ++i){
        bool isWhite = true;
        for(int j = 0; j < W; ++j){
            if(c[i][j] == '#') isWhite = false;
        }
        y[i] = isWhite;
    }
    for(int i = 0; i < W; ++i){
        bool isWhite = true;
        for(int j = 0; j < H; ++j){
            if(c[j][i] == '#') isWhite = false;
        }
        x[i] = isWhite;
    }
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(x[j] || y[i]) continue;
            cout << c[i][j];
        }
        cout << endl;
    }
}