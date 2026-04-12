#include <iostream>

using namespace std;

const int Z = 1e9+7;

int fp(int a, int x) {
    if (x == 0) {
        return 1;
    }
    if (x % 2 == 1) {
        return 1ll * a * fp(a, x - 1) % Z;
    }
    int t = fp(a, x / 2);
    return 1ll * t * t % Z;
}

int inv(int a) {
    return fp(a, Z - 2);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int fac[n*m-1];
    fac[0] = 1;
    for (int i = 1; i <= n * m - 2; i++) {
        fac[i] = 1ll * fac[i-1] * i % Z;
    }
    int c0 = 1ll * fac[n*m-2] * inv(fac[k-2]) % Z * inv(fac[n*m-k]) % Z;

    int c1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int dx1 = 1ll * i * (i + 1) / 2 % Z;
            int dx2 = 1ll * (n - 1 - i) * (n - i) / 2 % Z;
            int dy1 = 1ll * j * (j + 1) / 2 % Z;
            int dy2 = 1ll * (m - 1 - j) * (m - j) / 2 % Z;
            c1 = (c1 + 1ll * m * (dx1 + dx2)) % Z;
            c1 = (c1 + 1ll * n * (dy1 + dy2)) % Z;
        }
    }
    c1 = 1ll * c1 * inv(2) % Z;

    cout << 1ll * c0 * c1 % Z << endl;

    return 0;
}
