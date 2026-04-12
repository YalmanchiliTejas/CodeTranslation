#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }

    vector<bool> dl(100, false);
    for (int i = 0; i < H; i++) {
        bool dl_f = true;
        for (int j = 0; j < W; j++) {
            dl_f &= a[i][j] == '.';
        }
        dl[i] = dl_f;
    }

    vector<int> dc(100, false);
    for (int j = 0; j < W; j++) {
        bool dc_f = true;
        for (int i = 0; i < H; i++) {
            dc_f &= a[i][j] == '.';
        }
        dc[j] = dc_f;
    }

    for (int i = 0; i < H; i++) {
        if (dl[i]) continue;
        for (int j = 0; j < W; j++) {
            if (dc[j]) continue;
            cout << a[i][j];
        }
        cout << endl;
    }

}
