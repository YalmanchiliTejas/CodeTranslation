#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
using lint = long long;
const lint LINF = 1e18;
#define bit(n) ((lint)1 << n);

const lint MOD = 1e9 + 7;
// const lint MOD = 998244353;

template <lint mod>
class mod_integer {
    lint val;

    public:
    mod_integer(): val(0) {}
    mod_integer(lint init_val):
        val(init_val >= 0? init_val % mod: (init_val % mod + mod) % mod) {}
    
    bool operator ! () {
        return val == 0;
    }
    mod_integer operator - () {
        return mod_integer(-val);
    }
    mod_integer operator ++ (int) {
        mod_integer that = *this;
        this -> val = (this -> val + 1) % mod;
        return that;
    }
    mod_integer operator -- (int) {
        mod_integer that = *this;
        this -> val = (this -> val - 1 + mod) % mod;
        return that;
    }
    
    bool operator == (mod_integer that) {
        return val == that.val;
    }
    bool operator != (mod_integer that) {
        return val != that.val;
    }

    mod_integer& operator += (const mod_integer& that) {
        val = (val + that.val) % mod;
        return *this;
    }
    mod_integer& operator -= (const mod_integer& that) {
        val = (val - that.val + mod) % mod;
        return *this;
    }
    mod_integer& operator *= (const mod_integer& that) {
        val = (val * that.val) % mod;
        return *this;
    }
    mod_integer& operator /= (const mod_integer& that) {
        lint res = 1, n = that.val, p = mod - 2;
        while (p > 0) {
            if (p % 2 == 1) res = res * n % mod;
            n = n * n % mod;
            p /= 2;
        }
        val = val * res % MOD;
        return *this;
    }

    mod_integer operator + (const mod_integer& that) {
        return mod_integer(*this) += that;
    }
    mod_integer operator - (const mod_integer& that) {
        return mod_integer(*this) -= that;
    }
    mod_integer operator * (const mod_integer& that) {
        return mod_integer(*this) *= that;
    }
    mod_integer operator / (const mod_integer& that) {
        return mod_integer(*this) /= that;
    }

    friend istream& operator >> (istream& is, mod_integer& n) {
        lint init_val;
        cin >> init_val;
        n = mod_integer(init_val);
        return is;
    }
    friend ostream& operator << (ostream& os, const mod_integer& n) {
        return os << n.val;
    }
}; using mint = mod_integer<MOD>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    lint m, n, k;
    cin >> m >> n >> k;
    
    mint comb = 1;
    for (lint i = 0; i < k - 2; i++) {
        comb *= (m * n - 2 - i);
        comb /= i + 1;
    }

    mint num_m = 0;
    for (lint i = 1; i < m; i++) {
        num_m += i * (m - i);
    }
    mint num_n = 0;
    for (lint i = 1; i < n; i++) {
        num_n += i * (n - i);
    }

    cout << comb * (num_n * m * m + num_m * n * n) << endl;

    return 0;
}