// to format a document: ctrl + K -> ctrl + D

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for (int i = 0; i < H; i++) {
        cin >> a[i];
    }

    vector<bool> r(H, false), c(W, false);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (a[i][j] == '#') {
                r[i] = true;
                c[j] = true;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        bool flag = false;
        for (int j = 0; j < W; j++) {
            if (r[i] && c[j]) {
                cout << a[i][j];
                flag = true;
            }
        }
        if (flag) cout << endl;
    }

    return 0;
}