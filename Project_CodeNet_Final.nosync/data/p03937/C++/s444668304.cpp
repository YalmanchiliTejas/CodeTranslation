#include <bits/stdc++.h>

using namespace std;

bool a[15][15];

void umple(int x,int y) {
    a[x][y] = 0;
    if(a[x+1][y]) {
        umple(x+1, y);
        return;
    }
    if(a[x][y+1])
        umple(x, y+1);
}

int main() {
    int n, m;
    char ch;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            cin >> ch;
            a[i][j] = (ch == '#');
        }
    umple(1, 1);
    bool ok = 1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            ok = (ok && !a[i][j]);
    if(ok)
        cout << "Possible\n";
    else
        cout << "Impossible\n";
}
