#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vt<int> a(n);
    for (int &i : a) cin >> i;
    vt<int> sorta(a);
    sort(all(sorta));

    for (int i = 0; i < n; i++) {
        if (a[i] < sorta[n / 2]) cout << sorta[n / 2];
        else cout << sorta[n / 2 - 1];
        cout << '\n';
    }
}
