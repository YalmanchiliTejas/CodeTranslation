#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#include <string>
using namespace std;
int main(){
    int H,W;
    cin >> H >> W;
    vector<string> a(H);
    for(int i = 0;i < H;i ++){
        cin >> a.at(i);
    }
    vector<bool> isH(H,true);
    vector<bool> isW(W,true);
    for(int i = 0;i < H;i ++){
        for(int j = 0;j < W;j ++){
            if(a.at(i).at(j) == '#'){
                isH.at(i) = false;
                isW.at(j) = false;
            }
        }
    } 
    for(int i = 0;i < H;i ++){
        if(isH.at(i)) continue;
        for(int j = 0;j < W;j ++){
            if(isW.at(j)) continue;
            cout << a.at(i).at(j); 
        }
        cout << endl;
    }
}