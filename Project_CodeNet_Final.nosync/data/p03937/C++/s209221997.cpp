#include <bits/stdc++.h>

using namespace std;

int n, m;
char g[10][10];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", g[i]);
    }
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            if (g[a][b] == '.') continue;
            for (int c = 0; c < a; c++) {
                for (int d = b+1; d < m; d++) {
                    if (g[c][d] == '#') {
                        puts("Impossible");
                        return 0;
                    }
                }
            }
        }
    }
    puts("Possible");
    return 0;
}