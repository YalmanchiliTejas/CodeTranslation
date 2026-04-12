#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long ll;

class Mod {

public:
    ll MOD_;

    Mod(ll mod) { MOD_ = mod; }

    ll add(ll a, ll b) { return (a + b) % MOD_; }
    ll sub(ll a, ll b) { return (a - b + MOD_) % MOD_; }
    ll mul(ll a, ll b) { return (a * b) % MOD_; }
    
    ll pow(ll a, ll b) {
        ll res = 1;
        while (b > 0) {
            if (b & 1) res = mul(res, a);
            a = mul(a, a);
            b >>= 1;
        }
        return res;
    }

    ll inv(ll a) {
        ll b = MOD_;
        ll u = 1, v = 0;
        while (b > 0) {
            ll t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        u %= MOD_;
        if (u < 0) u += MOD_;

        return u;
    }


    ll *fac_, *fac_inv_, *inv_;
    int MAX_;

    void bc_init(int max) {
        MAX_ = max;
        fac_ = new ll[MAX_ + 1];
        fac_inv_ = new ll[MAX_ + 1];
        inv_ = new ll[MAX_ + 1];

        fac_[0] = 1;
        fac_[1] = 1;
        fac_inv_[0] = 1;
        fac_inv_[1] = 1;
        inv_[0] = 0;
        inv_[1] = 1;
        for (int i = 2; i <= MAX_; i++) {
            fac_[i] = mul(fac_[i-1], i);
            inv_[i] = MOD_ - (inv_[MOD_ % i] * (MOD_ / i)) % MOD_;
            fac_inv_[i] = fac_inv_[i - 1] * inv_[i] % MOD_;
        }
    }

    ll bc(ll n, ll k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return mul(fac_[n], mul(fac_inv_[k], fac_inv_[n-k]));
    }
};


int main()
{
    ll n, m, k;
    cin >> n >> m >> k;

    Mod mod(1000000007);

    ll a = mod.mul(n, mod.mul(m+1, m-1));
    ll b = mod.mul(m, mod.mul(n+1, n-1));
    ll c = mod.add(a, b);
    ll d = mod.mul(c, mod.mul(n, m));
    ll e = mod.mul(d, mod.inv(6));

    //cout << e << endl;

    mod.bc_init(n*m - 2);

    cout << mod.mul(e, mod.bc(n*m - 2, k - 2)) << endl;

    return 0;
}

