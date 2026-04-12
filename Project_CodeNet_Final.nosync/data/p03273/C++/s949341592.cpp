#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    bool ww[100] = {},hh[100] = {};
    char ch[100][100] = {};
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            cin >> ch[i][j];
            if(ch[i][j] == '#'){
                hh[i] = true;
                ww[j] = true;
            }
        }
    }

    for(int i = 0; i < h; ++i){
        if(!hh[i])continue;
        for(int j = 0; j < w; ++j){
            if(j == 0)cout << endl;
            if(!ww[j])continue;
            cout << ch[i][j];

        }
    }
    cout << endl;
}