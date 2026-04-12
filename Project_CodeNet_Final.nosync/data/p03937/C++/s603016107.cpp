#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <list>


using namespace std;

#define N 10

char mat[N][N];
bool vis[N][N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", mat[i]);
    }

    if (mat[0][0] == '#') {
        int cx = 0, cy = 0;
        bool ok = 1;
        vis[0][0] = 1;
        for (int i = 0; i < n; i++) {
            while (cy + 1 < m && mat[cx][cy + 1] == '#') {
                cy++;
                vis[cx][cy] = 1;
            }
            if (i == n - 1) break;
            if (mat[cx + 1][cy] == '#') {
                cx++;
                vis[cx][cy] = 1;
            }
            else {
                ok = 0;
                break;
            }
        }

        if (ok) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (mat[i][j] == '#') {
                        if (!vis[i][j]) {
                            ok = 0;
                            break;
                        }
                    }
                }
            }

            if (ok && cx == n - 1 && cy == m - 1)
                puts("Possible");
            else
                puts("Impossible");
        }
        else {
            puts("Impossible");
        }
    }
    else {
        puts("Impossible");
    }

    return 0;
}
