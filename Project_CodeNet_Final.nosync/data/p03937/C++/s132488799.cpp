#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool used[10][10];

int main() {/*
#ifdef __linux__
    freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
#else
    //freopen("cowrun.in", "r", stdin); freopen("cowrun.out", "w", stdout);
#endif*/
    ios::sync_with_stdio(0); //cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    char a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int x = 0, y = 0;

    if (a[x][y] != '#') {
        cout << "Impossible\n";
        return 0;
    }

    bool fl = true;

    while (true) {
        used[x][y] = true;
        if (x == n - 1 && y == m -1) {
            break;
        }
        if (x < n - 1 && a[x + 1][y] == '#') x++;
        else if (y < m - 1 && a[x][y + 1] == '#') y++;
        else {
            fl = false;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#' && !used[i][j]) {
                fl = false;
                break;
            }
        }
    }

    if (fl) {
        cout << "Possible\n";
    } else {
        cout << "Impossible\n";
    }

    return 0;
}