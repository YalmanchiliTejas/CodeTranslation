#include <bits/stdc++.h>

using namespace std;

using ll = long long;

char a[10][10];
int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            a[i][j] = s[j - 1];
        }
    }
    int x = 1, y = 1;
    while (true) {
        a[x][y] = '.';
        if (a[x + 1][y] == '#') {
            x++;
        } else if (a[x][y + 1] == '#') {
            y++;
        } else {
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '#') {
                cout << "Impossible\n";
                return 0;
            }
        }
    }
    cout << "Possible\n";
}