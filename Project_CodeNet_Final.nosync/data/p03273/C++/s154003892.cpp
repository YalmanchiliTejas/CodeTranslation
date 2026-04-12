#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int n, m;
char a[MAXN][MAXN];
bool allWRows[MAXN], allWCols[MAXN];

int main() {
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> (a[i] + 1);
    }

    for (int i = 1; i <= n; ++i) {
        allWRows[i] = 1;
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '#') {
                allWRows[i] = 0;
                break;
            }
        }
    }

    for (int j = 1; j <= m; ++j) {
        allWCols[j] = 1;
        for (int i = 1; i <= n; ++i) {
            if (a[i][j] == '#') {
                allWCols[j] = 0;
                break;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (allWRows[i])
            continue;
        for (int j = 1; j <= m; ++j) {
            if (allWCols[j])
                continue;
            cout << a[i][j];
        }
        cout << "\n";
    }

    return 0;
}