#include <iostream>

using namespace std;
const int Maxn = 10;
char f[Maxn][Maxn];

int main() {
    int h, w, s = 0;
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> f[i][j];
            if (f[i][j] == '#') ++s;
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == h - 1 && j == w - 1) break;
            if (f[i][j] == '#' && f[i + 1][j] != '#' && f[i][j + 1] != '#') {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    if (s != h + w - 1) cout << "Impossible" << endl;
    else cout << "Possible" << endl;

    return 0;
}