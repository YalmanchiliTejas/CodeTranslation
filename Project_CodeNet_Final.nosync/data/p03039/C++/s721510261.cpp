#include <bits/stdc++.h>
using namespace std;
using LL  = long long;
using VI  = vector<LL>;
using VVI = vector<VI>;
using VB  = vector<bool>;
using VS  = vector<string>;
using PII = pair<LL, LL>;
using VP  = vector<PII>;
#define PB           push_back
#define MP           make_pair
#define SZ(a)        LL((a).size())
#define EACH(x, c)   for (auto x : (c))
#define ALL(c)       (c).begin(), (c).end()
#define REVERSE(c)   reverse(ALL(c))
#define SORT(c)      stable_sort(ALL(c))
#define RSORT(c)     stable_sort((c).rbegin(), (c).rend())
#define FOR(i, a, b) for (LL i = (a); i < (b); ++i)
#define REP(i, n)    FOR(i, 0, n)
#define dump(x)      cerr << #x << " = " << (x) << endl;

const LL MOD = 1e9 + 7;
inline LL mod_add(LL a, LL b) { return (a + b) % MOD; }
inline LL mod_sub(LL a, LL b) { return (a + MOD - b) % MOD; }
inline LL mod_mul(LL a, LL b) { return ((a % MOD) * (b % MOD)) % MOD; }
LL mod_bipow(LL x, LL y) {   // x^y by bisection method
    if (y == 0) return 1;
    else if (y == 1) return x % MOD;
    else if (y % 2 == 0) {
        LL val = mod_bipow(x, (LL)(y / 2));
        return mod_mul(val, val);
    } else {
        LL val = mod_bipow(x, (LL)(y / 2));
        return mod_mul(mod_mul(val, val), x);
    }
}
LL mod_inv(LL x) { return mod_bipow(x, MOD - 2); }   // x^{-1} = x^{MOD-2} (MOD: prime number)
LL mod_div(LL a, LL b) { return mod_mul(a, mod_inv(b)); }   // a/b = a*b^{-1}

class Combination {
    VI facts, inv_facts;
public:
    Combination(LL N) : facts(N + 1), inv_facts(N + 1) {
        REP(i, N + 1) facts[i] = i == 0 ? 1 : mod_mul(facts[i - 1], i);
        for (LL i = N; i >= 0; i--) inv_facts[i] = i == N ? mod_inv(facts[N]) : mod_mul(inv_facts[i + 1], i + 1);   // (i!)^{-1}=((i+1)!)^{-1}*(i+1)
    }
    LL nCr(LL n, LL r) {
        return mod_mul(facts[n], mod_mul(inv_facts[r], inv_facts[n - r]));
    }
};

int main() {
    LL N, M, K;
    cin >> N >> M >> K;

    LL ans = 0;
    FOR(d, 1, N) {
        ans = mod_add(ans, mod_mul(d, mod_mul(mod_mul(mod_sub(N, d), M), M)));
    }
    FOR(d, 1, M) {
        ans = mod_add(ans, mod_mul(d, mod_mul(mod_mul(mod_sub(M, d), N), N)));
    }
    Combination c(N * M);
    ans = mod_mul(ans, c.nCr(N * M - 2, K - 2));
    cout << ans << endl;
	
    return 0;
}
