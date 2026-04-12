#include <bits/stdc++.h>

using namespace std;

int h, w, a[10][10], ok, x, y;
char b[10][10];

int main() {

    cin >> h >> w;

    for (int i = 1; i <= h; ++i){
        for (int j = 1; j <= w; ++j){
            cin >> b[i][j];
            if (b[i][j] == '#') a[i][j] = 1;
        }
    }

    a[1][1] = 2;
    ok = 1;
    x = 1;
    y = 1;
    while(ok != 0){
        ok = 0;
        if (a[x][y + 1] == 1) ok = 1;
        else if (a[x + 1][y] == 1) ok = 2;
        if (ok == 2){
            a[x + 1][y] = 2;
            x++;
        }
        else if (ok == 1){
            a[x][y + 1] = 2;
            y++;
        }
    }

    for (int i = 1; i <= h; ++i){
        for (int j = 1; j <= w; ++j){
            if (b[i][j] == '#' && a[i][j] != 2) {cout << "Impossible"; return 0;}
        }
    }

    cout << "Possible";

    return 0;

}
