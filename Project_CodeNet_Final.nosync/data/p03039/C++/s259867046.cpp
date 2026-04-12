#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

class ModCombination {
   private:
    ll max, mod, *fac, *finv, *inv;

   public:
    ModCombination(ll max, ll mod) {
        this->max = max;
        this->mod = mod;
        fac = new ll[max];
        finv = new ll[max];
        inv = new ll[max];
        inv[0] = 0;
        fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
        for (int i = 2; i < max; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
    ~ModCombination() {
        delete[] fac;
        delete[] finv;
        delete[] inv;
    }
    ll calc(ll n, ll k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }
};

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    ll mod = 1e9 + 7;
    ll max = N * M;

    ModCombination mc(max, mod);
    ll times = mc.calc(N * M - 2, K - 2);
    ll ans = 0;
    rep(y, N) rep(x, M) {
        ll cost = x + y;
        ll updown = (x == 0 || y == 0) ? 1 : 2;
        ans = (ans + times * cost % mod * ((N - y) * (M - x) * updown)) % mod;
    }
    cout << ans << endl;
    return 0;
}
