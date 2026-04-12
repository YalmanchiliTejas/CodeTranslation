#include <iostream>
#include <map>
#include <array>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    array<ll, 100> m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    sort(m.begin(), m.begin() + n, greater<ll>());
    ll ans = 0;
    while (m[0] >= n) {
        for (int i = 1; i < n; ++i) {
            m[i] += m[0] / n;
        }
        ans += m[0] / n;
        m[0] %= n;
        sort(m.begin(), m.begin() + n, greater<ll>());
    }
    cout << ans << endl;
}