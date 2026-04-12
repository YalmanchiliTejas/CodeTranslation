#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

string A[9];
int H, W;
bool ok = false;

void go(int x, int y, int num, int total_s) {
    if (num == total_s) ok = true;
    else if (!ok) {
        if (x < W-1 && A[y][x+1] == '#') {
            go(x+1, y, num+1, total_s);
        }
        if (y < H-1 && A[y+1][x] == '#') {
            go(x, y+1, num+1, total_s);
        }
    }
}

int main() {
    cin >> H >> W;
    rep(i, H) cin >> A[i];

    int total_s = 0;
    rep(i, H) rep(j, W) if (A[i][j] == '#') total_s++;

    go(0, 0, 1, total_s);

    if (ok) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}