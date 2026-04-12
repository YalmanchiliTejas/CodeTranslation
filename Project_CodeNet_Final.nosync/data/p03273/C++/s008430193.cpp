#include <bits/stdc++.h>    //C++の標準ライブラリのヘッダを全て読み込む
using namespace std;
#define _GLIBCXX_DEBUG

 
int main() {
    int h,w,nh = 0,nw = 0;
    cin >> h >> w;
    vector<vector<char>> a(h,vector<char>(w,'.'));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a.at(i).at(j);
        }
    }

    for (int i = 0; i < h; i++) {
        bool result = true;
        for (int j = 0; j < w; j++) {
            if(a.at(i).at(j) == '#'){
                result = false;
            } else {

            }
        }
        if(result == true){
            for (int j = 0; j < w; j++) {
                a.at(i).at(j) = '-';
            }
        } else {
        }
    }

    for (int i = 0; i < w; i++) {
        bool result = true;
        for (int j = 0; j < h; j++) {
            if(a.at(j).at(i) == '#'){
                result = false;
            } else {

            }
        }
        if(result == true){
            for (int j = 0; j < h; j++) {
                a.at(j).at(i) = '-';
            }
        } else {
        }
    }

    for (int i = 0; i < h; i++) {
        bool result = false;
        for (int j = 0; j < w; j++) {
            if(a.at(i).at(j) != '-'){
                result = true;
                cout << a.at(i).at(j);
            }
        }
        if(result == true){
            cout << endl;
        }
    }

}