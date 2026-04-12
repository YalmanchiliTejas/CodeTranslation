#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    ll z = 0;
    pii a[200005] = {}, b[200005] = {};
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= n; i++) if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
    for (int i = 1; i <= n; i++) b[i].first = a[i].second, b[i].second = a[i].first;
    sort(a + 1, a + n + 1); sort(b + 1, b + n + 1);
    z = 1ll * (a[n].first - a[1].first) * (b[n].first - b[1].first);
    if (a[1].second == b[n].first && a[1].second != b[n - 1].first) {
        cout << z << '\n';
        return 0;
    }
    int x = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i].second >= b[1].first) x = max(x, b[i].second);
        else x = max(x, b[i].first);
    }
    z = min(z, 1ll * (b[n].first - a[1].first) * (x - b[1].first));
    int c = a[1].second, d = a[1].second;
    for (int i = 2; i <= n; i++) {
        if (c >= a[i].first) {
            z = min(z, 1ll * (b[n].first - a[1].first) * (max(d, a[n].first) - a[i].first));
        }
        c = min(c, a[i].second);
        d = max(d, a[i].second);
    }
    cout << z << '\n';
}
