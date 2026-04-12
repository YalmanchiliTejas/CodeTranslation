#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int c[101][101], d[11][11];

bool judge(int a, int b) {
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            int dist = 114514;
            for (int k = 0; k <= 100; k++) {
                for (int l = 0; l <= 100; l++) {
                    dist = min(dist, i * k + j * l + c[k][l]);
                }
            }
            if (dist != d[i][j]) return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            cin >> d[i][j];
        }
    }

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 0; k <= 100; k++) {
                for (int l = 0; l <= 100; l++) {
                    c[k][l] = max(c[k][l], d[i][j] - i * k - j * l);
                }
            }
        }
    }

    if (judge(a, b)) {
        cout << "Possible" << endl;
        cout << 202 << " " << 101 * 101 + 200 << endl;
        for (int i = 1; i <= 100; i++) {
            cout << i << " " << i + 1 << " X" << endl;
        }
        for (int i = 102; i < 202; i++) {
            cout << i + 1 << " " << i << " Y" << endl;
        }
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                cout << i + 1 << " " << j + 102 << " " << c[i][j] << endl;
            }
        }
        cout << 1 << " " << 102 << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}