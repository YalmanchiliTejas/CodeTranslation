#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define l first
#define r second

using namespace std;

const int maxn = 2e5 + 1;

char v[9][9];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            cnt += (v[i][j] == '#');
        }
    }
    if (cnt != n + m - 1) {
        cout << "Impossible";
        return 0;
    }
    if (v[0][0] == '.' ||
        v[n - 1][m - 1] == '.') {
        cout << "Impossible";
        return 0;
    }
    int r = 0, c = 0;
    while (r < n - 1 || c < m - 1) {
        if (r < n - 1 && v[r + 1][c] == '#') {
            ++r; continue;
        }
        if (c < m - 1 && v[r][c + 1] == '#') {
            ++c; continue;
        }
        cout << "Impossible";
        return 0;
    }
    cout << "Possible";
    return 0;
}
