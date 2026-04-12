#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ull = unsigned long long;

ull r[500][500];
char x[500][500] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    auto transpose = [&](auto a) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(a[i][j], a[j][i]);
            }
        }
    };

    int s[2][500];
    ull u[2][500];
    for (int h = 0; h < 2; h++) {
        for (int i = 0; i < n; i++) {
            cin >> s[h][i];
        }
    }
    for (int h = 0; h < 2; h++) {
        for (int i = 0; i < n; i++) {
            cin >> u[h][i];
        }
    }

    for (int k = 0; k < 64; k++) {
        ull l = 1ULL << k;
        memset(x, -1, sizeof(x));

        for (int h = 0; h < 2; h++) {
            for (int i = 0; i < n; i++) {
                int b = (bool)(u[h][i] & l);
                if (!(s[h][i] ^ b)) continue;
                for (int j = 0; j < n; j++) {
                    x[i][j] = b;
                }
            }
            transpose(x);
        }
        for (int g = 0; g < 2; g++) {
            for (int h = 0; h < 2; h++) {
                for (int i = 0; i < n; i++) {
                    int b = (bool)(u[h][i] & l);
                    if (s[h][i] ^ b) continue;
                    int j1 = -1;
                    for (int j = 0; j < n; j++) {
                        if (x[i][j] == b) { j1 = -1; break; }
                        if (x[i][j] < 0) {
                            if (j1 >= 0) { j1 = -1; break; }
                            j1 = j;
                        }
                    }
                    if (j1 >= 0) x[i][j1] = b;
                }
                if (g) break;
                transpose(x);
            }
        }
        int i0 = -1, j0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (x[i][j] < 0) {
                    if (i0 < 0) {
                        i0 = i;
                        j0 = j;
                    }
                    x[i][j] = (i == i0) ^ (j == j0);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                r[i][j] ^= (ull)x[i][j] << k;
            }
        }
    }

    for (int h = 0; h < 2; h++) {
        for (int i = 0; i < n; i++) {
            ull p[2] = { numeric_limits<ull>::max(), 0 };
            for (int j = 0; j < n; j++) {
                p[0] &= r[i][j];
                p[1] |= r[i][j];
            }
            if (p[s[h][i]] != u[h][i]) {
                cout << -1 << endl;
                exit(0);
            }
        }
        transpose(r);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << r[i][j] << " \n"[j == n - 1];
        }
    }

    return 0;
}
