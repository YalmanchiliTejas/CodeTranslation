#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int H, W; cin >> H >> W;

    char A[H][W];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    bool row[H] = {false};
    for (int i = 0; i < H; i++) {
        bool flg = true;
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                flg = false;
            }
        }
        if (flg) {
            row[i] = true;
        }
    }

    bool col[W] = {false};
    for (int i = 0; i < W; i++) {
        bool flg = true;
        for (int j = 0; j < H; j++) {
            if (A[j][i] == '#') {
                flg = false;
            }
        }
        if (flg) {
            col[i] = true;
        }
    }

    for (int i = 0; i < H; i++) {
        if (!row[i]) {
            for (int j = 0; j < W; j++) {
                if (!col[j]) {
                    cout << A[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}