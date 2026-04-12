
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    char A[H][W];
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            cin >> A[h][w];
        }
    }

    int dy[4] = { 0, 1, 0, -1 };
    int dx[4] = { 1, 0, -1, 0 };

    int length = H + W - 1;
    pair<int, int> next = { 0, 0};

    if (A[0][0] == '.') {
        cout << "Impossible" << '\n';
        return 0;
    }
    while (--length) {
        int y = next.first;
        int x = next.second;

        int path = 0;
        for (int i = 0; i <= 1; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx < W && ny < H && A[ny][nx] == '#') {
                path++;
                next = make_pair(ny, nx);
                A[y][x] = '.';
            }
        }
        if (path == 0 || path == 2) {
            cout << "Impossible" << '\n';
            return 0;
        }

        for (int i = 2; i <= 3; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx < W && ny < H && A[ny][nx] == '#') {
                cout << "Impossible" << '\n';
                return 0;
            }
        }
    }
    A[H - 1][W - 1] = '.';

    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            if (A[h][w] == '#') {
                cout << "Impossible" << '\n';
                return 0;
            }
        }
    }

    cout << "Possible" << '\n';

    return 0;
}
