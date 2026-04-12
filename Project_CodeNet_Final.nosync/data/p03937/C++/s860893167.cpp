#include <bits/stdc++.h>

#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define bit(x) __builtin_popcount(x)
#define pb push_back
#define popb pop_back
#define ll long long

using namespace std;

int main() {
    srand('M' + 'R' + '.' + 'D' + 'U' + 'D' + 'E' + 'C');
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    char c[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }
    int x = 0, y = -1;
    while (x < n) {
        while (y + 1 < m && c[x][y + 1] == '#') {
            c[x][y + 1] = '.', y++;
        }
        x++;
        y--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '#') {
                cout << "Impossible\n";
                return 0;
            }
        }
    }
    cout << "Possible\n";
}
