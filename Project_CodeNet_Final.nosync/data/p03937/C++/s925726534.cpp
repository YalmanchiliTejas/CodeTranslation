#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h, w; cin >> h >> w;
    vector<string> a(h);
    for (auto &x: a) cin >> x;
    int x = 0, y = 0;
    while (true) {
        a[x][y] = '.';
        if (x == h-1 && y == w-1) break;
        if (x < h-1 && a[x+1][y] == '#') x++;
        else if (y < w-1 && a[x][y+1] == '#') y++;
        else {
            cout << "Impossible\n";
            return 0;
        } 
    }
    for (auto &s: a) {
        for (auto &x: s) {
            if (x == '#') {
                cout << "Impossible\n";
                return 0;
            }
        }
    }
    cout << "Possible\n";
    return 0;
}