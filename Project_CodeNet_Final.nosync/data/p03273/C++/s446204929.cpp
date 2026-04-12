#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    
    string field[105][105];
    bool width[W], height[H];
    memset( height, true, H );
    memset( width, false, W );
    
    for ( int i = 0; i < H; i++ ) {
        string s; cin >> s;
        int cnt = 0;
        for ( int j = 0; j < W; j++) {
            if ( s[j]=='#' ) {
                width[j] = true;
                cnt++;
            }
            field[i][j] = s[j];
        }
        if (cnt==0) height[i]=false;
    }
    
    for ( int i = 0; i < H; i++ ) {
        if (height[i]==false) continue;
        for ( int j = 0; j < W; j++) {
            if (width[j]==false) continue;
            cout << field[i][j];
        }
        cout << endl;
    }
}
