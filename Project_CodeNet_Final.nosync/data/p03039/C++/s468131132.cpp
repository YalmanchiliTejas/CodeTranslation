#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);

    long N, M, K;
    cin>>N>>M>>K;

    const long MOD = 1e9+7;
    auto mod = [&](long x) {return x % MOD;};
    vector<long> fact(200001);
    fact[0] = 1;
    for (int i = 1; i < fact.size(); i++)
        fact[i] = mod(fact[i-1] * i);
    auto mod_pow = [&](long x, long p) {
        long t = 1;
        long u = x;
        for (int i = 0; i < 32; i++) {
            if (p >> i & 1)
                t = mod(t * u);
            u = mod(u * u);
        }
        return t;
    };
    auto mod_div = [&](long x, long y) {
        return mod(x * mod_pow(y, MOD-2));
    };
    auto mod_comb = [&](long x, long y) -> long {
        if (x < 0 or y < 0)
            return 0;
        else
            return mod_div(fact[x], mod(fact[y] * fact[x-y]));
    };

    auto all_cost = [&](long x, long y) {
        long res = 0;
        for (long d = 2; d <= x; d++) {
            auto pos = mod((x-d+1) * mod_pow(y, 2));
            auto pat = mod_comb(mod(N*M-2), K-2);
            res = mod(res + mod((d-1) * mod(pos * pat)));
        }
        return res;
    };

    long ans = all_cost(N,M) + all_cost(M, N);
    ans = mod(ans);

    cout << ans << endl;

    
    return 0;
}

