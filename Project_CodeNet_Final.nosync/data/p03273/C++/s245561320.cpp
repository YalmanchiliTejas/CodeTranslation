#include<stdio.h>
#include<iostream>

using namespace std;

int H,W;
char tb[110][110];
bool tate[110],yoko[110];
int main(){
    cin >> H >> W;
    for(int i=0; i<H; i++) tate[i] = false;
    for(int i=0; i<W; i++) yoko[i] = false;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++){
            cin >> tb[i][j];
        }
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if( tb[i][j] == '#') {
                tate[j] = true;
                yoko[i] = true;
            }
        }
    }
    for(int i=0;i<H; i++){
        if( yoko[i] ) {
            for(int j=0; j<W; j++){
                if(tate[j]) cout << tb[i][j];
            }
        cout << endl;
        }
    }
    return 0;
}