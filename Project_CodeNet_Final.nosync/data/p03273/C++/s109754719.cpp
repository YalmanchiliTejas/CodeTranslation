#include <bits/stdc++.h>
using namespace std;
int main(void){
    int H,W;
    map<int,int>m;
    map<int,int>n;
    cin >> H >> W;
    char a[H][W];
    
    int x[W],y[H];
    
    for(int i = 0; i < W; i++) {
         
    }
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(a[i][j] == '.' ) {
                m[i]++;
            }
        }
        if(m[i] == W) {
            y[i] = 1;
        }
    }
    
    for(int i = 0; i < W; i++) {
        for(int j = 0; j < H; j++) {
            if(a[j][i] == '.' ) {
                n[i]++;
            }
        }
        if(n[i] == H) {
            x[i] = 1;
        }
    }

    for(int i = 0; i < H; i++) {
        if(y[i] != 1) {
            for(int j = 0; j < W; j++) {
                if(x[j] != 1) {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
    
}
