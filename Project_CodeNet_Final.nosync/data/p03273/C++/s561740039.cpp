#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int h, w;
    cin >> h >> w;
    vector<char> g(h * w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> g[w * i + j];
        }
    }
    bool bingo = true, change = true;
    while (change) {
        change = false;
        for (int i = 0; i < h; i++) {
            bingo = true;
            for (int j = 0; j < w; j++) {
                if (g[w * i + j] == '#') bingo = false;
            }
            if (bingo) {
                for (int j = 0; j < w; j++) {
                    if (g[w * i + j] == '.') change = true;
                    g[w * i + j] = 'x';
                }
            }
        }
        for (int i = 0; i < w; i++) {
            bingo = true;
            for (int j = 0; j < h; j++) {
                if (g[i + w * j] == '#') bingo = false;
            }
            if (bingo) {
                for (int j = 0; j < h; j++) {
                    if (g[i + w * j] == '.') change = true;
                    g[i + w * j] = 'x';
                }
            }
        }
    }
    bool exist = false;
    for (int i = 0; i < h; i++) {
        exist = false;
        for (int j = 0; j < w; j++) {
            if (g[i * w + j] != 'x') {
                cout << g[i * w + j];
                exist = true;
            }
        }
        if (exist) cout << endl;
    }
    return 0;
}