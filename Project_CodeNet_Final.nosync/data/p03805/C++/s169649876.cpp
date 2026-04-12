#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Welcome to my source code!

int main() {
    int n, m;
    cin >> n >> m;
    bool e[n + 1][n + 1] = {};
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        e[a][b] = true;
        e[b][a] = true;
    }
    int t[n - 1];
    for (int i = 0; i <= n - 2; i++) t[i] = i + 2;
    int ans = 0;
    do {
        bool flag = true;
        int cur = 1, i = 0;
        while (i < n - 1 && flag) {
            if (e[cur][t[i]]) {
                cur = t[i];
            } else {
                flag = false;
                break;
            }
            i++;
        }
        if (flag) ans++;
    } while (next_permutation(t, t+n-1));
    cout << ans << endl;
}