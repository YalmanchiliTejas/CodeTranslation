#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int H, W;
    char map[101][101];
    bool frow[101] = {false}, fcol[101] = {false};
    cin >> H >> W;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            cin >> map[i][j];
            if (map[i][j] == '#') {
                frow[i] = true;
                fcol[j] = true;
            }
        }
    }
    for (int i = 1; i <= H; ++i) {
        bool f = false;
        for (int j = 1; j <= W; ++j) {
            if (frow[i] && fcol[j]) {
                cout << map[i][j];
                f = true;
            }
        }
        if (f) {
            cout << endl;
        }
    }
    return 0;
}
