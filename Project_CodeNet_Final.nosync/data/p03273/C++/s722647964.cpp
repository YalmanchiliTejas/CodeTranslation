#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

int main(){
    char a[1000][1000];
    int H, W, cnt = 0;
    string str;
    cin >> H >> W;
    for(int i = 1; i <= H; ++i){
        cin >> str;
        for(int j = 1; j <= W; ++j){
            a[i][j] = str[j-1];
        }
    }

    
for(int m = 0; m < 100; ++m){
    for(int i = 1; i <= H; ++i){
        for(int k = 1; k <= W; ++k){
            if(a[i][k] == '.') ++cnt;
        }
        if(cnt == W){
            for(int j = i; j < H; ++j){
                for(int l = 1; l <= W; ++l){
                    a[j][l] = a[j+1][l];
                }
            }
            --H;
        }
        cnt = 0;
    }
    for(int i = 1; i <= W; ++i){
        for(int k = 1; k <= H; ++k){
            if(a[k][i] == '.') ++cnt;
        }
        if(cnt == H){
            for(int j = i; j < W; ++j){
                for(int l = 1; l <= H; ++l){
                    a[l][j] = a[l][j+1];
                }
            }
            --W;
        }
        cnt = 0;
    }
}

    for(int i = 1; i <= H; ++i){
        for(int j = 1; j <= W; ++j){
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}