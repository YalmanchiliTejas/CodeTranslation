#include <cstdio>
#include <cassert>
using namespace std;

const int N = 10;

char F[N][N];

int main() {
    int h, w;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", F[i]);
    }
    assert(F[0][0] == '#');
    int y = 0, x = 0;

    while (true) {
        F[y][x] = '.';
        if (y + 1 < h && F[y + 1][x] == '#') {
            y++;
        } else if (x + 1 < w && F[y][x + 1] == '#') {
            x++;
        } else {
            break;
        }
    }
    bool any = false;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            any |= F[i][j] == '#';
        }
    }
    puts(any ? "Impossible" : "Possible");
}
