#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int H,W;
    char a[100][101];

    scanf("%d %d", &H, &W);
    for(int i=0; i<H; i++){
            scanf("%s", a[i]);
    }

    bool b[100][100];
    int i,j;

    for(i=0; i<H; i++){
        for(j=0; j<W; j++){
            if(a[i][j]=='#'){
                break;
            }
        }
        if(j==W){
            for(j=0; j<W; j++){
                b[i][j]= true;
            }
        }
    }

    for(j=0; j<W; j++){
        for(i=0; i<H; i++){
            if(a[i][j]=='#'){
                break;
            }
        }
        if(i==H){
            for(i=0; i<H; i++){
                b[i][j]= true;
            }
        }
    }

    int sign = 0;

    for(i=0; i<H; i++){
        sign = 0;
        for(j=0; j<W; j++){
            if(b[i][j]==false) {
                printf("%c", a[i][j]);
                sign = 1;
            }
        }
        if(sign==1) {
            printf("\n");
        }
    }


    return 0;

}