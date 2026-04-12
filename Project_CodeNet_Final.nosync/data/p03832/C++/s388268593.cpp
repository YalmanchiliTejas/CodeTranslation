#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, x, y, u, v, d[1024][1024] = {};
    ll c[1024][1024] = {1};
    cin >> n >> x >> y >> u >> v;
    for (int i = 1; i <= n; i++) for (int j = 0; j <= i; j++) {
        c[i][j] = c[i - 1][j];
        if (j) {
            c[i][j] += c[i - 1][j - 1];
            if (c[i][j] >= mod) c[i][j] -= mod;
        }
    }
    d[x - 1][0] = 1;
    for (int i = x; i <= y; i++) {
        for (int j = 0; j <= n; j++) {
            d[i][j] = d[i - 1][j];
            for (int k = u; k <= v && j >= i * k; k++) {
                ll w = d[i - 1][j - i * k] * c[n - j + i * k][i * k] % mod;
                for (int l = 0; l < k; l++) w = w * c[i * k - i * l - 1][i - 1] % mod;
                d[i][j] += w;
                if (d[i][j] >= mod) d[i][j] -= mod;
            }
            //cout << d[i][j] << " \n"[j == n];
        }
    }
    cout << d[y][n] << '\n';
}

