#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (int)l; i <= (int)r; ++i)

using namespace std;
typedef long long ll;
const int Nmax = 3011;
const ll inf = 1e18;

int n, a[Nmax];
ll f[Nmax][Nmax][2];

ll dp(int l, int r, int t) {
    if (l > r) return 0;
    if (f[l][r][t] != -1) return f[l][r][t];
    ll res = -inf;
    if (t == 0) {
        res = max(dp(l + 1, r, 1 - t) + a[l], dp(l, r - 1, 1 - t) + a[r]);
    }
    if (t == 1) {
        res = min(dp(l + 1, r, 1 - t) - a[l], dp(l, r - 1, 1 - t) - a[r]);
    }
    return f[l][r][t] = res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
    }
    memset(f, -1, sizeof(f));
    cout << dp(1, n, 0);
}
