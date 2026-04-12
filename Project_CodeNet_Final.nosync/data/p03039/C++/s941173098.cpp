#include <bits/stdc++.h>
#define fst first
#define snd second
#define rep(n) for(lint I = 0; (I) < (lint)(n); ++(I))
#define repeat(i, n) for(lint i = 0; (i) < (lint)(n); ++(i))
#define repeat_to(i, n) for(lint i = 0; (i) <= (lint)(n); ++(i))
#define repeat_from(i, m, n) for(lint i = (m); (i) < (lint)(n); ++(i))
#define repeat_from_to(i, m, n) for(lint i = (m); (i) <= (lint)(n); ++(i))
#define repeat_reverse_from_to(i, m, n) for(lint i = (m); (i) >= (lint)(n); --(i))
#define el cout<<endl
#define es cout<<" "
#define dump(x) cout<<" "<<#x<<"="<<x
#define pdump(p) cout<<" "<<#p<<"=("<<p.fst<<","<<p.snd<<")"
#define vdump(v) for(size_t I=0; I<v.size(); ++I){cout<<" "<<#v<<"["<<I<<"]="<<v[I];} cout<<endl
using namespace std; using lint = long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<lint, lint>;
template<class T> vector<T> make_vec(size_t a){return vector<T>(a);}
template<class T, class... Ts> 
auto make_vec(size_t a, Ts... ts){return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));}

// n!, nPr, nCr, nHr 構造体 (宣言例 comb<lint, 1000000007> cm(1000000);)
template<typename Int, Int MOD>
struct comb {
    int sz;
    std::vector<Int> mfact, minv_fact;
    comb(int N) : sz(N + 1), mfact(sz), minv_fact(sz) {
        mfact[0] = 1;
        for (int i = 1; i <= sz; i++) mfact[i] = mfact[i - 1] * i % MOD;
        minv_fact[sz] = inv(mfact[sz]);
        for (int i = sz - 1; i >= 0; i--) minv_fact[i] = minv_fact[i + 1] * (i + 1) % MOD;
    }

    // res = first * p^second
    std::pair<Int, Int> fact_willson(Int n) const {
        Int e = 0;
        if (n <= sz) return std::make_pair(mfact[n], 0);
        Int res;
        std::tie(res, e) = fact_willson(n / MOD);
        e += n / MOD;
        if ((n / MOD) % 2 != 0) res = MOD - res;
        return std::make_pair(res * mfact[n % MOD] % MOD, e);
    }

    Int fact(Int n) const { return mfact[n]; }

    Int inv(Int n) const {
        return pow(n, MOD - 2);
    }

    Int pow(Int n, Int a) const {
        Int res = 1, exp = n;
        for(; a; a /= 2) {
            if (a & 1) res = res * exp % MOD;
            exp = exp * exp % MOD;
        }
        return res;
    }

    Int perm(Int n, Int r) {
        if (r < 0 || n < r) return 0;
        else return mfact[n] * minv_fact[n - r] % MOD;
    }

    Int binom_lucus(Int n, Int r) const {
        if (n < 0 || r < 0 || n < r) return 0;
        assert(n <= sz);
        if (n >= MOD) return binom(n % MOD, r % MOD) * binom(n / MOD, r / MOD);
        else return r > n ? 0 : mfact[n] * minv_fact[n - r] * minv_fact[r];
    }

    Int binom(Int n, Int r) const {
        if (n < 0 || r < 0 || n < r) return 0;
        return mfact[n] * minv_fact[r] % MOD * minv_fact[n - r] % MOD;
    }

    Int homo(Int n, Int r) const {
        if (n < 0 || r < 0) return 0;
        return r == 0 ? 1 : binom(n + r - 1, r);
    }
};

int main(void) {
    const lint MOD = 1e9 + 7;
    lint n, m, k;
    cin >> n >> m >> k;
    
    lint ans = 0;
    repeat_from_to (d, 1, n-1) {
        ans += d * (n-d) * m * m;
        ans %= MOD;
    }
    repeat_from_to (d, 1, m-1) {
        ans += d * (m-d) * n * n;
        ans %= MOD;
    }
    
    comb<lint, MOD> cm(1000000);
    ans *= cm.binom(n * m - 2, k - 2);
    ans %= MOD;
    cout << ans << endl;
}