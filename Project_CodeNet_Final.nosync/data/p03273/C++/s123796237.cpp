#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    scanf("%d %d", &h, &w);
    char a[h][w];
    bool hflag[h];
    fill(hflag, hflag+h, false);
    bool wflag[w];
    fill(wflag, wflag+w, false);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("\n%c", &a[i][j]);
            if (a[i][j] == '#') {
                hflag[i] = true;
                wflag[j] = true;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        if (!hflag[i])
            continue;
        for (int j = 0; j < w; j++) {
            if (!wflag[j])
                continue;
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
