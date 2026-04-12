#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int H, W; cin >> H >> W;
    vector<string> G(H);
    rep(i, H) {
        cin >> G.at(i);
    }
    int x = 0, y = 0;
    int dir = 0; // 0: right 1: down
    set<pair<int,int>> S;
    S.insert({0,0});
    bool possible = true;
    while (1) {
        if (x < W - 1 && y < H - 1 && G[y][x + 1] == '#' && G[y+1][x] == '#') {
            possible = false;
            break;
        } 
        if ((dir == 0 && y > 0 && G[y - 1][x] == '#') ||
            (dir == 1 && x > 0 && G[y][x - 1] == '#')) {
            possible = false;
            break;
        }
        if (x == W - 1 && y == H - 1) {
            possible = true;
            break;
        } else if (x >= W || y >= H) {
            possible = false;
            break;
        }
        if (x < W - 1 && G[y][x + 1] == '#') {
            x = x + 1;
            dir = 0;
        } else if (y < H - 1 && G[y+1][x] == '#') {
            y = y + 1;
            dir = 1;
        } else {
            possible = false;
            break;
        }
    }
    if (possible) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
}