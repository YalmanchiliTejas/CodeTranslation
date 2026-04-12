#include <iostream>
using namespace std;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int main (void) {
    int H, W;

    cin >> H >> W;

    string A[H];
    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int cnt = 0;
            for (int d = 0; d < 4; d++) {
                int ny = i + dy[d];
                int nx = j + dx[d];
                if (0 <= ny && ny < H && 0 <= nx && nx < W && A[ny][nx] == '#') {
                    cnt++;
                }
            }
            if (cnt > 1) {
                cout << "Impossible" << endl;
                return 0;
            }
            A[i][j] = '.';
        }
    }

    cout << "Possible" << endl;

    return 0;
}
