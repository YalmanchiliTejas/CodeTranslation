#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    int H,W;
    char a[100][100];
    int sum_H=0;
    int sum_W=0;
    cin >> H >> W;
    sum_H = H * '.';
    sum_W = W * '.';
    int skip_H[100] = {0};
    int skip_W[100] = {0};
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> a[i][j];
        }
    }
    int cnt =0;
    for(int i=0;i<H;i++){
        cnt = 0;
        for(int j=0;j<W;j++){
            cnt += a[i][j];
        }
        if(cnt == sum_W){
            skip_H[i] = 1;
        }        
    }
    for(int i=0;i<W;i++){
        cnt = 0;
        for(int j=0;j<H;j++){
            cnt += a[j][i];
        }
        if(cnt == sum_H){
            skip_W[i] = 1;
        }        
    }        
    for(int i=0;i<H;i++){
        if(skip_H[i] == 1){
            continue;
        }
        for(int j=0;j<W;j++){
            if(skip_W[j] == 1){
                continue;
            }
            cout << a[i][j];
        }
        cout << '\n';
    }
}
