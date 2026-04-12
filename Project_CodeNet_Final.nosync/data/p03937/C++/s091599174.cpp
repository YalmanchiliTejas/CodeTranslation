#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int NMax = 2e5 + 5;
const int LIM = 1e9;

char c[10][10];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }

    int x, y;
    x = y = 1;

    if(c[x][y] == '.') {
        cout << "Impossible";
        return 0;
    }

    bool ok = true;
    while(ok == true) {
        ok = false;
        c[x][y] = '.';
        if(c[x][y + 1] == '#') {
            ok = true;
            y++;
        } else {
            if(c[x + 1][y] == '#') {
                x++;
                ok = true;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(c[i][j] != '.') {
                cout << "Impossible";
                return 0;
            }
        }
    }

    cout << "Possible";

    return 0;

}
