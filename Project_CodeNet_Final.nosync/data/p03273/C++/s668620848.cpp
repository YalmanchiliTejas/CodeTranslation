#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    string A[H];
    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }

    int row[H] = {false};
    int col[W] = {false};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        if (row[i]) {
            for (int j = 0; j < W; j++) {
                if (col[j]) {
                    cout << A[i][j];
                }
            }
            cout << endl;
        }
    }
    cout << endl;
    return 0;    
}