#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll patty(ll k) {
    return pow(2LL, k + 1) - 1;
}

ll total(ll k) {
    return pow(2LL, k + 2) - 3;
}

ll pts(ll x, ll k) {
    if (x <= 1) {
        if (k == 0 && x == 1)
            return 1;
        return 0;
    }
    if (x >= total(k))
        return patty(k);
    if (x <= 1 + total(k - 1))
        return pts(x - 1, k - 1);
    return patty(k - 1) + pts(x - 2 - total(k - 1), k - 1) + 1;
}

int main() {
    ll n, x; cin >> n >> x;
    cout << pts(x, n);
    return 0;
}

