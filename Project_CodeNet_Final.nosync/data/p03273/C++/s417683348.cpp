#include <iostream>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    char a[H][W];
    bool del[H][W];

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            cin >> a[i][j];
        }
    }


    for (int i=0; i<H; i++) {

        bool f = false;
        for (int j=0; j<W; j++) {
            if(a[i][j] == '#') {
                f = true;
            }
        }

        for (int j=0; j<W; j++) {
            del[i][j] = f;
        }
    }


    for (int i=0; i<W; i++) {

        bool f = false;
        for (int j=0; j<H; j++) {
            if(a[j][i] == '#') {
                f = true;
            }
        }

        for (int j=0; j<H; j++) {
            if(del[j][i]) {
                del[j][i] = f;
            }
        }
    }


    for (int i=0; i<H; i++) {
        bool ret = false;
        for (int j=0; j<W; j++) {
            if(del[i][j]) {
                cout << a[i][j];
                ret = true;
            }
        }
        if (ret) {
            cout << "\n";
        }
    }
  
    return 0;
}
