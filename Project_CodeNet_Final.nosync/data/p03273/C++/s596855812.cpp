#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int w, h; cin >> w >> h;
    char c[w][h];
    for(int i = 0; i < w; ++i) {
        int count = 0;
        for(int j = 0; j < h; ++j) {
            cin >> c[i][j];
            if(c[i][j] == '.') ++count;
        }
        if(count == h) {
            for(int k = 0; k < h; ++k) {
                c[i][k] = 'a';
            }
        }
    }

    for(int i = 0; i < h; ++i) {
        int count = 0;
        for(int j = 0; j < w; ++j) {
            if(c[j][i] == '.' || c[j][i] == 'a') ++count;
        }
        if(count == w) {
            for(int k = 0; k < w; ++k) {
                c[k][i] = 'a';
            }
        }
    }

    for(int i = 0; i < w; ++i) {
        bool flag = 0;
        for(int j = 0; j < h; ++j) {
            if(c[i][j] != 'a') {
                cout << c[i][j];
                flag = 1;
            }
        }
        if(flag) cout << '\n';
    }
}


