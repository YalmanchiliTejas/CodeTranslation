#include <bits/stdc++.h>
using namespace std;
char s[10][10];
int n, m, stp, tot;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    int x = 0, y = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (s[i][j] == '#') tot++;
    }
    for (;;) {
        if (s[x + 1][y] == '#') {
            x++;
            stp++;
            continue;
        }
        if (s[x][y + 1] == '#') {
            y++;
            stp++;
            continue;
        }
        break;
    }
    puts(stp == tot ? "Possible" : "Impossible");
    return 0;
}