#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int A, B;
int d[11][11];
int f[101][101];

signed main() {
    cin >> A >> B;
    for (int x = 1; x <= A; x++) {
        for (int y = 1; y <= B; y++) {
            cin >> d[x][y];
        }
    }
    for (int a = 0; a <= 100; a++) {
        for (int b = 0; b <= 100; b++) {
            f[a][b] = 0;
            for (int x = 1; x <= A; x++) {
                for (int y = 1; y <= B; y++) {
                    f[a][b] = max(f[a][b], d[x][y] - x * a - y * b);
                }
            }
        }
    }
    for (int x = 1; x <= A; x++) {
        for (int y = 1; y <= B; y++) {
            int cur = LLONG_MAX;
            for (int a = 0; a <= 100; a++) {
                for (int b = 0; b <= 100; b++) {
                    cur = min(cur, x * a + y * b + f[a][b]);
                }
            }
            if (d[x][y] != cur) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;
    cout << 202 << " " << 200 + 101 * 101 << endl;
    for (int i = 1; i <= 100; i++) {
        cout << i << " " << i + 1 << " X" << endl;
        cout << i + 101 << " " << i + 102 << " Y" << endl;
    }
    for (int a = 0; a <= 100; a++) {
        for (int b = 0; b <= 100; b++) {
            cout << a + 1 << " " << 202 - b << " " << f[a][b] << endl;
        }
    }
    cout << 1 << " " << 202 << endl;
    return 0;
}
