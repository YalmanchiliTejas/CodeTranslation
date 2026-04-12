#include "bits/stdc++.h"
using namespace std;
int main(){
    int H,W;
    cin >> H >> W;
    int i,j;
    char c;
    int B[H][W];
    int P[W],Q[H];//sum of tate/yoko
    for(i=0;i<H;i++) Q[i]=0;
    for(j=0;j<W;j++) P[j]=0;
    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            cin >> c;
            if(c == '#') B[i][j] = 1;
            else B[i][j] = 0;
            P[j] += B[i][j];
            Q[i] += B[i][j];
        }
    }
    for(i=0;i<H;i++){
        if(Q[i]==0) continue;
        for(j=0;j<W;j++){
            if(P[j]==0)continue;
            if(B[i][j]==0) cout << ".";
            else cout << "#";
        }
        cout << endl;
    }
    return 0;
}