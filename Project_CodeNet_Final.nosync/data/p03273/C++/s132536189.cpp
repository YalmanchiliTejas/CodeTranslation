#include <iostream>
using namespace std;

int main() {
    int H,W;
    cin >> H >> W;
    char array[H][W];
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            cin >> array[i][j];
        }
    }

    for (int i=0; i<H; i++) {
        bool flg = true;
        for (int j=0; j<W; j++) {
            if (array[i][j] == '#') {
                flg = false;
                break;
            }
        }
        if (flg) {
            for (int j=0; j<W; j++) {
                array[i][j] = ' ';
            }
        }
    }

    for (int j=0; j<W; j++) {
        bool flg = true;
        for (int i=0; i<H; i++) {
            if (array[i][j] == '#') {
                flg = false;
                break;
            }
        }
        if (flg) {
            for (int i=0; i<H; i++) {
                array[i][j] = ' ';
            }
        }
    }

    for (int i=0; i<H; i++) {
        bool flg = false;
        for (int j=0; j<W; j++) {
            if (array[i][j] != ' ') {
                cout << array[i][j];
                flg = true;
            }
        }
        if (flg)
            cout << endl;
    }
    return 0;
}