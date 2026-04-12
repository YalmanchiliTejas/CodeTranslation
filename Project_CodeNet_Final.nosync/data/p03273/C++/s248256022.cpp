#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    char a[100][100];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> a[i][j];
        }
    }
    //行の圧縮
    int flag = 0;
    int comp[100][100] = {};
    char first;
    for(int i=0;i<H;i++){
        first = a[i][0];
        if(first == '.'){
            for(int j=1;j<W;j++){
                if(a[i][j] != first)
                    flag = 1;
            }
            if(flag == 0){ //圧縮
                for(int j=0;j<W;j++)
                    comp[i][j] = 1;
            }
        }
        flag = 0;
    }
    //列の圧縮
    for(int j=0;j<W;j++){
        first = a[0][j];
        if(first == '.'){
            for(int i=1;i<H;i++){
                if(a[i][j] != first)
                    flag = 1;
            }
            if(flag == 0){ //圧縮
                for(int i=0;i<H;i++)
                    comp[i][j] = 1;
            }
        }
        flag = 0;
    }
    //出力
    char last = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(comp[i][j] == 0){
                cout << a[i][j];
                last = 1;
            }
        }
        if(last == 1)
            cout << endl;
        last = 0;
    }
    return 0;
}