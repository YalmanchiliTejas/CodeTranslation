#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for (int j=0; j < H; ++j) {
        cin >> a[j];
    }
    vector<bool> row(H), col(W);
    for (int j=0; j < H; ++j) {
        bool isBlank = true;
        for (int k=0; k < W; ++k) {
            if (a[j][k] == '#') {
                isBlank = false;
                break;
            }
        }
        if (isBlank) {
            row[j] = false;
        } else {
            row[j] = true;
        }
    }
    for (int j=0; j < W; ++j) {
        bool isBlank = true;
        for (int k=0; k < H; ++k) {
            if (a[k][j] == '#') {
                isBlank = false;
                break;
            }
        }
        if (isBlank) {
            col[j] = false;
        } else {
            col[j] = true;
        }
    }
    for (int j=0; j < H; ++j) {
        if (row[j]) {
        for (int k=0; k < W; ++k) {
            if (col[k]) {
                cout << a[j][k];
            }
        }
        cout << endl;
        }
    }
}