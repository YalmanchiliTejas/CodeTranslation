#include <bits/stdc++.h>
using namespace std;

int main() {
    int H,W;
    cin >> H >> W;
    char a[H][W];
    
    for ( int i = 0; i < H; ++i){
        for ( int j = 0; j < W; ++j){
            cin >> a[i][j];
        }
    }
    
    
    int hcount = 0; // 横が全て'.'のラインの数を数える
    bool flg = true;
    vector<int> h(H,0);
    for ( int i = 0; i < H; ++i){
        flg = true;
        for ( int j = 0; j < W; ++j){
            if ( a[i][j] == '#' ) {
                flg = false;
                h[i] = 1;
            }
        }
        if ( flg ) ++ hcount;
    }
    
    char a2[H-hcount][W];
    int idx = 0;
    for ( int i = 0; i < H; ++i){
        if ( h[i] == 0 ) continue;
        for ( int j = 0; j < W; ++j){
            a2[idx][j] = a[i][j];
        }
        ++idx;
    }
    

    int wcount = 0;
    vector<int> w(W,0);
    for ( int i = 0; i < W; ++i){
        flg = true;
        for ( int j = 0; j < H-hcount; ++j){
            if ( a2[j][i] == '#' ){
                flg = false;
                w[i] = 1;
            }
        }
        if ( flg ) ++ wcount;
    }
    
    char a3[H-hcount][W-wcount];
    idx = 0;
    for ( int i = 0; i < W; ++i){
        if ( w[i] == 0 ) continue;
        for ( int j = 0; j < H-hcount; ++j){
            a3[j][idx] = a2[j][i];
        }
        ++idx;
    }
    
    for ( int i = 0; i < H-hcount; ++i){
        for ( int j = 0; j < W-wcount; ++j){
            cout << a3[i][j];
        }
        cout << endl;
    }
    
    
    
    return 0;
}
