#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int H, W;
string A[8];

signed main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }
    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                cnt++;
            }
        }
    }
    if (cnt == H + W - 1) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}
