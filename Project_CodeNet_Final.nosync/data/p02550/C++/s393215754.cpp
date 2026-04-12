#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, x, m;
    cin >> n >> x >> m;
    vector<vector<long long>> to(50, vector<long long>(m));
    vector<vector<long long>> s(50, vector<long long>(m));
    for (long long i = 0; i < m; i++) {
        to[0][i] = i * i % m;
        s[0][i] = i;
    }
    for (int i = 1; i < 50; i++) {
        for (int j = 0; j < m; j++) {
            to[i][j] = to[i - 1][to[i - 1][j]];
            s[i][j] = s[i - 1][j] + s[i - 1][to[i - 1][j]];
        }
    }
    long long ans = 0;
    long long pos = x;
    for (int i = 49; i >= 0; i--) {
        if (n & (1LL << i)) {
            ans += s[i][pos];
            pos = to[i][pos];
        }
    }
    cout << ans << '\n';
    return 0;
}