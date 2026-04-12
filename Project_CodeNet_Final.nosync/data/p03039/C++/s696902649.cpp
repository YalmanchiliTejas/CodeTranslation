#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < n; i++)

const ll mod = 1000000007;

ll modpow(ll A, ll N) {
    ll RET = 1;
    // 例えば3=101(2)なので、下位bitから順に1ならa倍する
    while (N) {
        if (N & 1) RET = RET * A % mod;
        A = A * A % mod;
        N >>= 1;
    }
    return RET;
}

ll comb(ll N, ll R) {
    if (N < 0 || R < 0 || N < R) return 0;
    // numerator / denominator
    ll NUME = 1, DENO = 1;
    R = min(R, N-R);
    for (int i = 1; i <= R; i++) {
        NUME = NUME * N % mod;
        DENO = DENO * i % mod;
        N--;
    }
    return NUME * modpow(DENO, mod-2) % mod;
}

int main() {
    ll n, m, k, ans;
    cin >> n >> m >> k;
    ans = comb(n*m-2, k-2);
    ans = ans * m * n % mod;
    ans = ans * (m * n - 1) % mod;
    ans = ans * (m + n) % mod;
    ans = ans * modpow(6, mod-2) % mod;
    cout << ans << endl;
    return 0;
}