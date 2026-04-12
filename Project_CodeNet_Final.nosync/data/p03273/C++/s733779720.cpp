#include <iostream>

using namespace std;

int main()
{
    int H, W, count;
    char a[128][128];
    bool row_white[128], col_white[128];

    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        row_white[i] = true;
        for (int j = 0; j < W; j++) {
            if (a[i][j] == '#') {
                row_white[i] = false;
                break; 
            }
        }
    }
    for (int j = 0; j < W; j++) {
        col_white[j] = true;
        for (int i = 0; i < H; i++) {
            if (a[i][j] == '#') {
                col_white[j] = false;
                break;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        if (row_white[i] == false) {
            for (int j = 0; j < W; j++) {
                if (col_white[j] == false) {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
}