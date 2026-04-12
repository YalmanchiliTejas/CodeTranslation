#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define int long long
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e18;

struct Combination {
    vector<int64_t> fact, rfact;
    Combination(int sz) : fact(sz + 1), rfact(sz + 1) {
        fact[0] = 1;
        for(int i = 1; i < fact.size(); i++){
            fact[i] = fact[i - 1] * i % mod;
        }
        rfact[sz] = inv(fact[sz]);
        for(int i = sz - 1; i >= 0; i--){
            rfact[i] = rfact[i + 1] * (i + 1) % mod;
        }
    }
    int64_t inv(int x) const {
        return pow(x, mod - 2);
    }
    int64_t pow(int64_t x, int64_t n) const {
        int64_t ret = 1;
        while(n > 0){
            if(n & 1) (ret *= x) %= mod;
            (x *= x) %= mod;
            n >>= 1;
        }
        return (ret);
    }
    int64_t P(int n, int r) const {
        if(r < 0 || n < r) return (0);
        return (fact[n] * rfact[n - r] % mod);
    }

    int64_t C(int p, int q) const {
        if(q < 0 || p < q) return (0);
        return (fact[p] * rfact[q] % mod * rfact[p - q] % mod);
    }

    int64_t H(int n, int r) const {
        if(n < 0 || r < 0) return (0);
        return (r == 0 ? 1 : C(n + r - 1, r));
    }
};

Combination cb(500010);

int calc(int n, int m){
    int res = 0;
    rep(i, 1, n){
        int tmp = i * (n - i) * m % mod * m % mod;
        res += tmp;
        res %= mod;
    }
    return res;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    int ans = (calc(n, m) + calc(m, n)) % mod * cb.C(n * m - 2, k - 2) % mod;
    cout << ans << endl;
}