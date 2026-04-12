/*
 *
 */
#include <cstdio>
#include <iostream>

using namespace std;

char a[8][9];

int main(){
    //freopen("a3.in", "r", stdin);
    int h, w;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; ++i) {
        scanf("%s", &a[i]);
    }

    int curH = 0, curW = 0;

    while (curH != h-1 || curW != w-1) {
        a[curH][curW] = '.';
        if (curH+1 < h && a[curH+1][curW] == '#') {curH++;}
        else if (curW+1 < w && a[curH][curW+1] == '#') {curW++;}
        else break;
    }
    a[curH][curW] = '.';
    bool ans = true;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == '#') ans = false;
        }
    }
    printf(ans ? "Possible\n" : "Impossible\n");

    return 0;
}
