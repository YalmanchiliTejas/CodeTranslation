
#include <iostream>
#include <string.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

int h, w;
char grid[10][10];
bool vis[10][10];

int main() {
    memset(grid, 0, sizeof(grid));
    memset(vis, 0, sizeof(vis));
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++) {
        scanf("%s", &grid[i][1]);
    }
    int x = 1, y = 1;
    vis[1][1] = true;
    bool possible = true;
    while (x != h || y != w) {
        //printf("%d %d\n", x, y);
        bool right = false, down = false;
        if (y < w) {
            if (grid[x][y + 1] == '#') right = true;
        }
        if (x < h) {
            if (grid[x + 1][y] == '#') down = true;
        }
        if (right && down) {
            possible = false;
            break;
        } else if (right) {
            y++;
        } else if (down) {
            x++;
        } else {
            possible = false;
            break;
        }
        vis[x][y] = true;
    }
    if (!possible) {
        printf("Impossible\n");
        return 0;
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (grid[i][j] == '#') {
                if (!vis[i][j]) {
                    printf("Impossible\n");
                    return 0;
                }
            }
        }
    }
    printf("Possible\n");
}