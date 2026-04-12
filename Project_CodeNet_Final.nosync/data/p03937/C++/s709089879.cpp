#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>
#include <cmath>
#include <functional>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e5 + 100;
const int MAX = 1e9 + 1;
//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
char mp[10][10];
int n, m;

bool in(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

bool ok() {
    int cx = 0, cy = 0;
    while (!(cx == n - 1 && cy == m - 1)) {
        int rx = cx, ry = cy + 1;
        int dx = cx + 1, dy = cy;
        if (in(rx, ry)) {
            if (mp[rx][ry] == '#') {
                if (in(dx, dy) && mp[dx][dy] == '#')
                    return false;
                cx = rx, cy = ry;
            }
            else {
                if (!(in(dx, dy) && mp[dx][dy] == '#'))
                    return false;
                cx = dx, cy = dy;
            }
        }
        else {
            if (!(in(dx, dy) && mp[dx][dy] == '#'))
                return false;
            cx = dx, cy = dy;
        }
    }
    return true;

}

int main() {
    int i, j;
    cin >> n >> m;
    int cnt = 0;
    for (i = 0; i < n; ++i) {
        cin >> mp[i];
        for (j = 0; j < m; ++j)
            if (mp[i][j] == '#')
                ++cnt;
    }
    cout << (cnt == n + m - 1 && ok() ? "Possible\n" : "Impossible\n");
    return 0;
}
