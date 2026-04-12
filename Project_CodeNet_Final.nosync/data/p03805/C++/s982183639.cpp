#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Welcome to my source code!

int main() {
    int n, m;
    cin >> n >> m;
    bool e[n][n] = {};
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        e[a - 1][b - 1] = true;
        e[b - 1][a - 1] = true;
    }
    int t[n - 1];
    for (int i = 0; i <= n - 2; i++) t[i] = i + 1;
    int ans = 0;
    do {
        bool flag = true;
        int cur = 0;
        for (int i = 0; i <= n - 2; i++) {
            if (e[cur][t[i]]) cur = t[i];
            else flag = false;
        }
        if (flag) ans++;
    } while (next_permutation(t, t+n-1));
    cout << ans << endl;
}