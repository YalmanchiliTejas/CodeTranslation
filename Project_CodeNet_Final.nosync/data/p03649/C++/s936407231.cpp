#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[55], n, oper[55], sum;

bool check(const ll& x) {
    for (int i = 0; i < n; i++) {
        ll l = 0, r = oper[i] = 2e16, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (mid * n + n - 1 >= a[i] + x - mid) {
                r = mid - 1;
                oper[i] = mid;
            } else {
                l = mid + 1;
            }
        }
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) sum += oper[i];
    return x >= sum;
}

bool docheck(ll& mid) {
    for (ll i = 0; i <= 7500 && mid - i >= 0; i++)
        if (check(mid - i)) return mid -= i, true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int i;
    for (i = 0; i < n; i++) if (a[i] >= n) break;
    if (i == n) return printf("0"), 0;
    ll l = 0, r = 5e17, mid, res;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (docheck(mid)) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << res;
}