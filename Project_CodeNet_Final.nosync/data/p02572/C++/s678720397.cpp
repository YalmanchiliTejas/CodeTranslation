#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
#define rrep(i, n) for (int i = (int)(n)-1; 0 <= i; i--)
#define rrep1(i, n) for (int i = (int)(n); 1 <= i; i--)

#define each(it, c) \
    for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define all(obj) (obj).begin(), (obj).end()

#define pcount __builtin_popcount
#define SZ(x) ((int)(x).size())
#define LEN(x) ((int)(x).length())

#define dump(x) cerr << #x << " = " << (x) << endl;

#define endl "\n"

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

typedef long long lint;
const lint MOD = 1e9 + 7;

using namespace std;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<lint> a(n);
    rep(i, n) cin >> a[i];
    lint sum = 0;
    rep(i, n) {
        sum += a[i];
        sum %= MOD;
    }
    lint ans = 0;
    rep(i, n) {
        lint tmp = (sum - a[i]) % MOD;
        if (tmp < 0) tmp += MOD;
        ans += tmp * a[i];
        ans %= MOD;
    }
    cout << (ans * modinv(2, MOD)) % MOD << endl;
}