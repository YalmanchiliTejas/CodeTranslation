#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> masu(H, vector<char>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> masu.at(i).at(j);
        }
    }
    
    for(int i = 0; i < H; i++) {
        bool white = true;
        for(int j = 0; j < W; j++) {
            if(masu.at(i).at(j)=='#') white = false;
        }
        if(white) {
            for(int j = 0; j < W; j++) masu.at(i).at(j) = 'x';
        }
    }
    
    for(int j = 0; j < W; j++) {
        bool white = true;
        for(int i = 0; i < H; i++) {
            if(masu.at(i).at(j)=='#') white = false;
        }
        if(white) {
            for(int i = 0; i < H; i++) masu.at(i).at(j) = 'x';
        }
    }
    
    for(int i = 0; i < H; i++) {
        bool skip = true;
        for(int j = 0; j < W; j++) {
            if(masu.at(i).at(j)!='x') {
                cout << masu.at(i).at(j);
                skip = false;
            }
            if(j==W-1 && !skip) cout << endl;
        }
    }
}
