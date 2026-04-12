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

inline LL mod_add(LL a, LL b) {
    return (a + b) % MOD;
}

inline LL mod_sub(LL a, LL b) {
    return (a + MOD - b) % MOD;
}

inline LL mod_mul(LL a, LL b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

LL mod_bipow(LL x, LL y) {   // power using bisection method
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

LL mod_inv(LL x) {   // compute x^{-1}=x^{MOD-2} (when MOD is a prime number) using Fermat theorem
    return mod_bipow(x, MOD - 2);
}

LL mod_div(LL a, LL b) {   // using a/b=a*b^{-1}
    return mod_mul(a, mod_inv(b));
}

void calcFactorial(LL N, VI& facts, VI& inv_facts) {
    REP(i, N + 1) facts[i] = i == 0 ? 1 : mod_mul(facts[i - 1], i);
    for (LL i = N; i >= 0; i--) inv_facts[i] = i == N ? mod_inv(facts[N]) : mod_mul(inv_facts[i + 1], i + 1);   // (i!)^{-1}=((i+1)!)^{-1}*(i+1)
}

int main() {
    LL N, M, K;
    cin >> N >> M >> K;

    VI facts(N * M + 1);   // k! for k=0,...,n
    VI inv_facts(N * M + 1);   // (K!)^{-1} for k=0,...,n
    calcFactorial(N * M, facts, inv_facts);
    LL ncr = mod_mul(facts[N * M - 2], mod_mul(inv_facts[K - 2], inv_facts[N * M - K]));
    LL ans = 0;
    FOR(d, 1, N) {
        ans = mod_add(ans, mod_mul(d, mod_mul(mod_mul(mod_sub(N, d), M), M)));
    }
    FOR(d, 1, M) {
        ans = mod_add(ans, mod_mul(d, mod_mul(mod_mul(mod_sub(M, d), N), N)));
    }
    ans = mod_mul(ans, ncr);
    cout << ans << endl;
	
    return 0;
}
