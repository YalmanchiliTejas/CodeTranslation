/*
    Author:    DreamCat4er
    Created:   29.08.2020 15:57:29
*/
#include <bits/stdc++.h>
using namespace std;

const long long base = (long long)(1e9 + 7);

long long a[(int)(2e5 + 500)];
long long sf[(int)(2e5 + 500)];

long long mul(long long x, long long y) {
    return (x * y) % base;
}

void add_self(long long &x, long long y) {
    x += y;
    x %= base;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = n - 1; i >= 0; --i)
        add_self(sf[i], (i + 1 == n ? 0 : sf[i + 1]) + a[i]);

    long long ans = 0;
    for (int i = 0; i < n - 1; ++i)
        add_self(ans, mul(a[i], sf[i + 1]));

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
                
    #ifdef _LOCAL
        int t;
        cin >> t;
        for (int _t = 0; _t < t; ++_t) {
            cout << "Case " << _t << " :\n";
            solve();
            cout << "\n";
        }
    #else
        solve();
    #endif // _LOCAL

    return 0;
}