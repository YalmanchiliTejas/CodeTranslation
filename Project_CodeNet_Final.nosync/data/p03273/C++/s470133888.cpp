#include<bits/stdc++.h>
using namespace std;

int main(void){
    int h, w;
    cin >> h >> w;
    char ma[110][110];
    int usei[110], usej[110];
    for(int i=0;i<110;++i){
        usei[i] = 1;
        usej[i] = 1;
    }
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            cin >> ma[i][j];
        }
    }
    for(int i=0;i<h;++i){
        int flg=1;
        for(int j=0;j<w;++j){
            if(ma[i][j]!='.') flg=0;
        }
        if(flg) usei[i] = 0;
    }
    for(int i=0;i<w;++i){
        int flg=1;
        for(int j=0;j<h;++j){
            if(ma[j][i]!='.') flg=0;
        }
        if(flg) usej[i] = 0;
    }
    for(int i=0;i<h;++i){
        if(usei[i]==0) continue;
        for(int j=0;j<w;++j){
            if(usej[j]==0) continue;
            cout << ma[i][j];
        }
        cout << endl;
    }
}
