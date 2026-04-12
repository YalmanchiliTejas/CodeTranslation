#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    int index_h[h]={};
    int index_w[w]={};
    //配列入力&横が全て.のindexを取得
    char a[h][w]={};
    for(int i=0;i<h;i++){
        int count = 0;
        for(int j=0;j<w;j++){
            cin >> a[i][j];
            if(a[i][j]=='.')count++;
        }
        if(count==w){
            index_h[i]++;
        }
    }
    //縦が全て.のindexを取得
    for(int j=0;j<w;j++){
        int count = 0;
        for(int i=0;i<h;i++){
            if(a[i][j]=='.')count++;
        }
        if(count==h){
            index_w[j]++;
        }
    }
    //出力
    for(int i=0;i<h;i++){
        bool flag = false;
        for(int j=0;j<w;j++){
            if(index_h[i]==0 && index_w[j]==0){
                cout << a[i][j];
                flag = true;
            }
        }
        if(flag) cout << endl;
    }
    return 0;
}
