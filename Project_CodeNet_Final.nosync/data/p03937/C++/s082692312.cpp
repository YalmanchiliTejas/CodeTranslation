#include <bits/stdc++.h>

using namespace std;


char c[8][8];

int main() {
    int H, W;
    cin >> H >> W;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> c[i][j];

    int x = 0;
    int y = 0;

    while (c[y][x] == '#') {
        c[y][x] = '.';
        if (y == H - 1 && x == W - 1) {
            for (int i = 0; i < H; i++)
                for (int j = 0; j < W; j++) {
                    if (c[i][j] == '#') {
                        cout << "Impossible" << endl;
                        return 0;
                    }
                }
            cout << "Possible" << endl;
            return 0;
        }
        if (x + 1 < W && c[y][x + 1] == '#') {
            x++;
        } else if (y + 1 < H && c[y + 1][x] == '#') {
            y++;
        }
    }
    cout << "Impossible" << endl;

}
