#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; ++i) cin >> grid[i];
    for (int i = 0; i < h; ++i) {
        bool can = true;
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '#') {
                can = false;
                break;
            }
        }
        if (can) for (int j = 0; j < w; ++j) grid[i][j] = '$';
    }
    for (int j = 0; j < w; ++j) {
        bool can = true;
        for (int i = 0; i < h; ++i) {
            if (grid[i][j] == '#') {
                can = false;
                break;
            }
        }
        if (can) for (int i = 0; i < h; ++i) grid[i][j] = '$';
    }
    for (int i = 0; i < h; ++i) {
        bool flag = true;
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] != '$') {
                flag = false;
                cout << grid[i][j];
            }
        }
        if (!flag) cout << endl;
    }
}
