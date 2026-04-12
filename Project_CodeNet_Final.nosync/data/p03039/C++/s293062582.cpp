#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define ALL(a) a.begin(),a.end()
#define INIT(a,b) memset(a,b,sizeof(a))
using lint = long long int;

class Combination {
private:
    const int N;
    const lint MOD;
    std::vector<lint> fact, inv;
    
    lint powmod(lint x, lint k) {
        lint res = 1;
        while (k) {
            if (k & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            k >>= 1;
        }
        return res;
    }
    
    void precomputation() {
        fact[0] = fact[1] = 1;
        for (int i=2; i<=N; ++i) fact[i] = (fact[i-1] * i) % MOD;
        for (int i=0; i<=N; ++i) inv[i] = powmod(fact[i], MOD-2);
    }
    
public:
    Combination(int N, lint MOD) : N(N), MOD(MOD), fact(N + 1), inv(N + 1) {
        precomputation();
    }
    
    lint compute(int n, int k, bool duplicate = false) {
        if (duplicate) return compute(n+k-1, k);
        if (n < k) return 0;
        lint res = fact[n];
        res = (res * inv[n-k]) % MOD;
        res = (res * inv[k]) % MOD;
        return res;
    }
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    const lint MOD = lint(1e9) + 7;
    Combination comb(N * M, MOD);

    auto func = [&](int X, int Y) {
        lint ret = 0;
        for_(d,1,X) {
            lint add = ((X - d) * Y * Y) % MOD;
            add = (d * add) % MOD;
            ret = (ret + add) % MOD;
        }
        return ret;
    };

    lint ans = (func(N, M) + func(M, N)) % MOD;
    ans = (ans * comb.compute(N * M - 2, K - 2)) % MOD;
    cout << ans << endl;
}