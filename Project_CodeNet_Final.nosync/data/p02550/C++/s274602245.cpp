#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, x, m;
ll ans;
ll cnt[100005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> x >> m;
    ll k = 1;
    ll last = -1;
    ll curr = x;
    while (!cnt[curr]) {
        cnt[curr] = k++;
        last = curr;
        curr = curr * curr % m;
    }

    ll head = cnt[curr];
    ll tail = cnt[last];
    ll len_front = head - 1;
    ll len_cycle = (tail - head + 1);

    ll sum_front = 0;
    ll y = x;
    while (y != curr) {
        sum_front += y;
        y = (y * y) % m;
    }

    ll sum_cycle = 0;
    y = curr;
    do {
        sum_cycle += y;
        y = (y * y) % m;
    } while (y != curr);

    if (n < len_front) {
        for (ll i = 0; i < n; i++) {
            ans += x;
            x = (x * x) % m;
        }
    } else {
        ans += sum_front;
        ans += sum_cycle * ((n - len_front) / len_cycle);
        ll lim = (n - len_front) % len_cycle;
        x = curr;
        for (ll i = 0; i < lim; i++) {
            ans += x;
            x = (x * x) % m;
        }
    }
    cout << ans << endl;
}