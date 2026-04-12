#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int h, w;
char g[10][10];

bool go(int y, int x) {
    if (g[y][x] == '.') return false;
    if (y == h-1 && x == w-1) return true;

    if (g[y+1][x] == '#') return go(y+1,x);
    if (g[y][x+1] == '#') return go(y,x+1);
    return false;
}

int main() {
    scanf("%d%d", &h, &w);
    int nm = 0;
    FO(y,0,h) {
        scanf("%s", g[y]);
        FO(x,0,w) nm += g[y][x] == '#';
    }
    if (nm != h+w-1 || !go(0,0)) {
        printf("Impossible\n");
        return 0;
    } else {
        printf("Possible\n");
        return 0;
    }
}

