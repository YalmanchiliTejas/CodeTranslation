#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        v[i] = i;

    vector<bool> ok(n + 1);
    ok[1] = ok[2] = true;
    int pos = 1;

    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        if (v[x] == 1) pos = y;
        if (v[y] == 1) pos = x;
        swap(v[x], v[y]);
        if (1 < pos) ok[v[pos - 1]] = true;
        if (pos < n) ok[v[pos + 1]] = true;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += ok[i];
    cout << cnt << '\n';
    return 0;
}
