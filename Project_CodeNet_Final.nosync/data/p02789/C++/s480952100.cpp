#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

void PUNKS_NOT_DEAD() {
    int n, m;
    cin >> n >> m;
    cout << (m == n ? "Yes" : "No");
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false), cin.tie(0);
    PUNKS_NOT_DEAD();
}