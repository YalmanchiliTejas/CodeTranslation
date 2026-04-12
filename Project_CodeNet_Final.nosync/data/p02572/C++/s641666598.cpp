#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)
#define MOD 1000000007


long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll ans = 0;
    rep(i, N) {
        ans += A[i];
        ans%=MOD;
    }
    ans *= ans;
    ans %= MOD;
    rep(i, N) {
        ans -= A[i]*A[i];
        if (ans < (ll)0) {
            ans += ((-ans)/MOD + 1) * MOD;
        }
        ans %= MOD;
    }
    cout << (ans * modinv(2, MOD)) % MOD << endl;
}
