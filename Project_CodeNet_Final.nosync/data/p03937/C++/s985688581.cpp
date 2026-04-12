#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;

void solve();

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}

void solve() {
    int H,W;
    cin >> H >> W;
    char map[H][W];
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> map[i][j];
        }
    }
    int X[H];
    int XX[H];

    for(int i = 0; i < H; i++) {
        X[i] = 0;
        XX[i] = 0;
        for(int j = 0; j < W; j++) {
            if(map[i][j] == '#') X[i] = j;
        }
        for(int j = W-1; j >= 0; j--) {
            if(map[i][j] == '#') XX[i] = j;
        }
    }
    bool ok = true;
    for(int i = 1; i < H; i++) {
        if(X[i-1] <= X[i]) ok = true;
        else {
            ok = false;
            break;
        }
        if(XX[i] >= X[i-1]) ok = true;
        else {
            ok = false;
            break;
        }
    }
    if(ok) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }

    
}