#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n, x;

ll fast_pow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if ((b & 0x1))
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

ll get_num(ll total, ll x) {
    if (x == total) {
        return (total + 1ll) / 2ll;
    }
    if (x == 1) {
        return 0;
    }
    x--;
    ll tt = (total - 3ll) / 2ll;
    if (x < tt) return get_num(tt, x);
    else if (x == tt) return get_num(tt, x);
    else if (x == tt + 1) return 1 + get_num(tt, x - 1);
    else {
        ll ans1 = (tt + 1ll) / 2ll;
        x -= tt;
        return ans1 + 1 + get_num(tt, x - 1);
    }
    return 0;
}
int main() {
    cin >> n >> x;
    ll total = 4ll * fast_pow(2, n) - 3;
    ll ans = get_num(total , x);
    cout << ans << endl;
}