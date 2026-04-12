#include <bits/stdc++.h>

typedef long double ld;
typedef long long ll;

using namespace std;

const int inf = 1e9 + 1;
const ld pi = acos(-1);
const ll p = 998244353;

const int maxsz = 1e7 + 2;

ll factorial[maxsz];
ll invfact[maxsz];

ll POWER(ll x, ll y) {
    if (y == 0) return 1;
    ll f = POWER(x, y / 2);
    f *= f;
    f %= p;
    if (y % 2 == 1) {
        f *= x;
        f %= p;
    }
    return f;
}

ll Pow(ll x, ll y) {
    ll x1 = x % p;
    x1 += p;
    x1 %= p;
    ll y1 = y % (p - 1);
    y1 += (p - 1);
    y1 %= (p - 1);
    return POWER(x1, y1);
}

ll inverse(ll x) {
    return Pow(x, p - 2);
}

void podfact() {
    factorial[0] = 1;
    for (int i = 1; i < maxsz; i++) {
        ll k = i;
        factorial[i] = factorial[i - 1] * k;
        factorial[i] %= p;
    }
    invfact[maxsz - 1] = inverse(factorial[maxsz - 1]);
    for (int i = maxsz - 2; i >= 0; i--) {
        ll k = i;
        invfact[i] = (k + 1) * invfact[i + 1];
        invfact[i] %= p;
    }
}

ll C(int n, int k) {
    ll x = factorial[n] * invfact[k];
    x %= p;
    x *= invfact[n - k];
    return x % p;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cout << setprecision(20);

    podfact();
    int n;
    cin >> n;
    int k = n / 2;
    ll x = 1;
    for (int i = 0; i < k; i++) {
        x *= 2;
        x %= p;
    }
    ll ans = (x * C(n, k)) % p;
    // cout << ans;
    for (int i = 0; i < k; i++) {
        ll y = x * 2;
        y -= C(k + i, i);
        x = y % p;
        ans += (x * C(n, k - i - 1)) % p;
        ans %= p;
    }
    cout << (ans + p) % p;
    return 0;
}
