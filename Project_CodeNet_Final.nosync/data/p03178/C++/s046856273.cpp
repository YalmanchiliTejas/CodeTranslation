#include <bits/stdc++.h>
#include "bits/stdc++.h"

using namespace std;

#define int long long

#ifndef bhupixb
    #define var(...)
    #define stl(...)
#endif

#define rep(i,a,b) for (int i = a; i <= (int)b; ++i)
#define f first
#define s second

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

const int maxn = 10002;
int32_t dp[maxn][100][2];

string s;
int d;

int32_t go(int pos, int rem, bool f = false) {
    if (pos == s.size()) {
        return rem == 0;
    }
    auto &ref = dp[pos][rem][f];
    if (ref != -1) {
        return ref;
    }
    int curDig = s[pos] - '0';
    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        if (i > curDig && f == false) {
            break;
        }
        int new_rem = (rem + i);
        while (new_rem >= d) {
            new_rem -= d;
        }
        ans = add(ans, go(pos + 1, new_rem, f | (i < curDig)));
    }
    return ref = ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> s >> d;
    cout << sub(go(0, 0), 1);
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