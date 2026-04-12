#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    char s[h][w];
    bool t[h][w];
    int u[h][w];

    int i, j;
    for(i = 0; i < h; i++){
        for(j = 0; j < w; j++){
            t[i][j] = true;
        }
    }

    for(i = 0; i < h; i++){
        for(j = 0; j < w; j++){
            cin >> s[i][j];
        }
    }

    for(i = 0; i < h; i++){
        for(j = 0; j < w; j++){
            if (s[i][j] == '#') {
                u[i][j] = 1;
            }
            else {
                u[i][j] = 0;
            }
        }
    }

    int tmp = 0;
    int k;
    for(i = 0; i < h; i++, tmp = 0){
        for(j = 0; j < w; j++){
            tmp += u[i][j];
        }
        if (tmp == 0) {
            for(k = 0; k < w; k++){
                t[i][k] = false;
            }
        }
    }

    for(i = 0; i < w; i++, tmp = 0){
        for(j = 0; j < h; j++){
            tmp += u[j][i];
        }
        if (tmp == 0) {
            for(k = 0; k < h; k++){
                t[k][i] = false;
            }
        }
    }

    for(i = 0; i <h; i++, tmp = 0){
        for(j = 0; j < w; j++){
            if (t[i][j] == true) {
                cout << s[i][j];
            }
            for(k = 0; k < w; k++){
                tmp += u[i][k];
            }
            if (tmp != 0 && j == w - 1) {
                cout << endl;
            }
        }
    }
}
