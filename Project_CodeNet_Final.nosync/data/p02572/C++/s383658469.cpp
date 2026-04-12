#include <bits/stdc++.h>
#include "bits/stdc++.h"

using namespace std;

#define int long long

#ifndef bhupixb
    #define var(...)
    #define stl(...)
#endif

#define single_test


constexpr int mod = 1e9 + 7;

struct M {
    unsigned v;
    M(long long a = 0) : v((a %= mod) < 0 ? a + mod : a) {}
    M& operator+=(M r) { if ((v += r.v) >= mod) v -= mod; return *this; }
    M& operator-=(M r) { if ((v += mod - r.v) >= mod) v -= mod; return *this; }
    M& operator*=(M r) { v = (uint64_t)v * r.v % mod; return *this; }
};

uint32_t add(M a, M b) { return (a += b).v; }
uint32_t mul(M a, M b) { return (a *= b).v; }
uint32_t sub(M a, M b) { return (a -= b).v; }

uint32_t po(M x, int n) {
    M res(1);
    while (n > 0) {
        res *= (n & 1 ? x : 1);
        x *= x; n /= 2;
    }
    return res.v;
}

const int N = 2e5 + 4;

int a[N], post[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i > 0; --i) {
        post[i] = add(post[i+1], a[i]);
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans = add(ans, mul(a[i], post[i+1]));
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    #ifndef single_test
        cin >> t;
    #endif
    for (int i = 1; i <= t; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}