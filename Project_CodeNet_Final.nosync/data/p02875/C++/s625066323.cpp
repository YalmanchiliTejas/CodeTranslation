#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 998244353;

int modpow(int b, int e) {
    if (e == 0) return 1;
    if (e % 2 == 1) return 1LL * b * modpow(b, e - 1) % MOD;
    return modpow(1LL * b * b % MOD, e / 2);
}

inline int inv(int x) {
    return modpow(x, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int ans = modpow(3, n);
    int cur = 0;
    int term = 1;
    int p = 2;
    // n choose k * 2^k for k in range()
    for (int k = n; k > n / 2; --k) {
        cur += 1LL * term * p % MOD;
        if (cur >= MOD)
            cur -= MOD;
        // going from n!/k!(n-k)! to n!/(k-1)!(n-k+1)!
        // multiply by k/(n-k+1)
        term = 1LL * term * inv(n - k + 1) % MOD;
        term = 1LL * term * k % MOD;
        p += p;
        if (p >= MOD)
            p -= MOD;
    }

    int res = ans - cur;
    if (res < 0) res += MOD;
    cout << res << '\n';
 
    return 0;
}
