#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<int, bool> H_tmp, W_tmp;
    int H, W; cin >> H >> W;
    vector<string> a(H, "");
    for (int i = 0; i < H; i++) cin >> a[i];

    for (int i = 0; i < H; i++) {
        bool T = true;
        for (int j = 0; j < W; j++) {
            if (a[i][j] == '#') {
                T = false; break;
            }
        }
        H_tmp[i] = T;
    }

    for (int i = 0; i < W; i++) {
        bool T = true;
        for (int j = 0; j < H; j++) {
            if (a[j][i] == '#') {
                T = false; break;
            }
        }
        W_tmp[i] = T;
    }

    for (int i = 0; i < H; i++) {
        if (H_tmp[i] == false) {
            for (int j = 0; j < W; j++) {
                if (W_tmp[j] == true) continue;
                cout << a[i][j];
            }
            cout << endl;
        }
    }
}
