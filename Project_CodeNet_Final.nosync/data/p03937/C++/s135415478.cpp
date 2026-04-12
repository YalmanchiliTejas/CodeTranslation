#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

void fail() {
    printf("Impossible\n");
    exit(0);
}

int h, w;
char grid[8][9];
int main() {
    scanf("%d%d", &h, &w);
    for (int i = 0; i < h; ++i) {
        scanf("%s", grid[i]);
    }
    if (grid[0][0] != '#') fail();
    int x = 0, y = 0;
    while (x < h - 1 || y < w - 1) {
        grid[x][y] = '.';
        bool r = x < h - 1 && grid[x + 1][y] == '#';
        bool d = y < w - 1 && grid[x][y + 1] == '#';
        if (r == d) fail();
        if (r) ++x;
        else ++y;
    }
    if (x != h - 1 || y != w - 1) fail();
    grid[x][y] = '.';
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '#') fail();
        }
    }
    printf("Possible\n");
	return 0;
}
