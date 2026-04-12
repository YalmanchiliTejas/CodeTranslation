#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >>H >> W;
    char map[H][W];
    for (int i=0; i<H; i++)
        for (int j=0; j<W;j++) cin >> map[i][j];
    char d[H][W];
    int s=0;
    for (int i=0; i<H; i++){
        bool t=true;
        for (int j=0; j<W;j++){
            if (map[i][j]=='#') t=false;
        }
        if (!t){
            for (int j=0; j<W;j++){
                d[s][j]=map[i][j];
            }
            s++;
        }
    }
    char e[H][W];
    int u=0;
    for (int i=0; i<W; i++){
        bool t=true;
        for (int j=0; j<s;j++){
            if (d[j][i]=='#') t=false;
        }
        if (!t){
            for (int j=0; j<s;j++){
                e[j][u]=d[j][i];
            }
            u++;
        }
    }
    for (int i=0; i<s; i++){
        for (int j=0; j<u; j++){
            printf("%c", e[i][j]);
            if (j==u-1) printf("\n");
        }
    }
    
}
