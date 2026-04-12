#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W; cin >> H >> W;
    vector<string> a(H);
    for (int i = 0; i < H; i++) cin >> a[i];

    vector<bool> vh(H), vw(W);
    for (int i = 0; i < H; i++) {
        bool flag = true;
        for (int j = 0; j < W; j++) {
            if (a[i][j] == '#') {
                flag = false;
                break;
            }
        }
        if (flag) vh[i] = true;
    }
    for (int j = 0; j < W; j++) {
        bool flag = true;
        for (int i = 0; i < H; i++) {
            if (a[i][j] == '#') {
                flag = false;
                break;
            }
        }
        if (flag) vw[j] = true;
    }

    for (int i = 0; i < H; i++) {
        if (vh[i]) continue;
        for (int j = 0; j < W; j++) {
            if (vw[j]) continue;
            cout << a[i][j];
        }
        cout << "\n";
    }
}