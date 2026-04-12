#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char g[10][10];
int h, w;

bool poss(int i, int j) {
    if (i == 0 && j == 0 && g[i][j] != '#')
        return 0;
    if (i == h-1 && j == w-1)
        return (g[i][j] == '#');

    if (((g[i+1][j] == '#')^(g[i][j+1] == '#')) == 0)
        return 0;
    if (g[i+1][j] == '#')
        return poss(i+1, j);
    else
        return poss(i, j+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> h >> w;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> g[i][j];

    int ct = 0;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            ct += (g[i][j] == '#');

    if (ct != h+w-1) {
        cout << "Impossible\n";
        return 0;
    }

    if (poss(0, 0)) {
        cout << "Possible\n";
        return 0;
    } else {
        cout << "Impossible\n";
        return 0;
    }
}