#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

ll n, pref[N];
int x, m, a[N], visited[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x >> m;

    a[1] = pref[1] = x;
    visited[x] = 1;

    int cycle_start, cycle_end;
    for (int i = 2;; i++) {
        a[i] = (ll)a[i - 1] * a[i - 1] % m;
        if (visited[a[i]]) {
            cycle_start = visited[a[i]];
            cycle_end = i - 1;
            break;
        } else {
            visited[a[i]] = i;
            pref[i] = a[i] + pref[i - 1];
        }
    }

    if (n <= cycle_end) {
        cout << pref[n] << '\n';
    } else {
        ll ans = pref[cycle_end];
        n -= cycle_end;
        int cycle_length = cycle_end - cycle_start + 1;
        ans += (n / cycle_length) * (pref[cycle_end] - pref[cycle_start - 1]) + (pref[cycle_start - 1 + n % cycle_length] - pref[cycle_start - 1]);
        cout << ans << '\n';
    }
    return 0;
}