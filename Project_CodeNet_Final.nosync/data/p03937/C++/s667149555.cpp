#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (int i = 0; i < h; i++) cin >> g[i];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int cnt = 0;
            if (i + 1 < h && g[i + 1][j] == '#') cnt++;
            if (j + 1 < w && g[i][j + 1] == '#') cnt++;
            if (cnt == 2) return false;
        }
    }
    return true;
}

int main() {
    puts(solve() ? "Possible" : "Impossible");
}
