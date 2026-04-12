#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    char a[H][W];
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            cin >> a[i][j];
        }
    }

    // 行について探索
    int line[H];
    for (int i=0; i<H; i++) {
        int flag = 0;
        for (int j=0; j<W; j++) {
            if (a[i][j] == '#') {
                flag++;
            }
        }
        if (flag == 0) {
            line[i] = 1;
        } else {
            line[i] = 0;
        }
    }

    // 列について探索
    int column[W];
    for (int j=0; j<W; j++) {
        int flag = 0;
        for (int i=0; i<H; i++) {
            if (a[i][j] == '#') {
                flag++;
            }
        }
        if (flag == 0) {
            column[j] = 1;
        } else {
            column[j] = 0;
        }
    }

    // 出力
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (line[i] == 0 && column[j] == 0) {
                cout << a[i][j];
            }
        }
        if (line[i] == 0){
            cout << endl;
        }
    }

    return 0;
}