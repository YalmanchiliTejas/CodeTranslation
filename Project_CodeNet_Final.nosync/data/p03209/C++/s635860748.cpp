#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <class INT_T> INT_T powi(INT_T x, INT_T y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    if (y & 1) return powi(x*x, y/2) * x;
    return powi(x*x, y/2);
}

inline ll layer(ll lv) { return 4 * powi((ll)2, lv) - 3; }
inline ll patty(ll lv) { return powi((ll)2, lv+1) - 1; }

ll solve(ll lv, ll x)
{
    if (lv <= 0) {
        return x > 0 ? 1 : 0;
    }
    if (x <= 1) {
        return 0;
    } else if (x <= 1 + layer(lv-1)) {
        return solve(lv-1, x-1);
    } else if (x == 1 + layer(lv-1) + 1) {
        return 1 + patty(lv-1);
    } else {
        return patty(lv-1) + 1 + solve(lv-1, min(layer(lv-1), x-1-layer(lv-1)-1));
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    ll n, x;
    cin >> n >> x;

    cout << solve(n, x) << endl;
}
