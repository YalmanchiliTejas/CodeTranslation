#include <iostream>
using namespace std;
#define M 1000000007

class ModComb {
    long long *fact, *facti;
    const int mod;
public:
    explicit ModComb(int n, int m) : mod(m) {
        fact = new long long[n+1];
        facti = new long long[n+1];
        fact[0] = 1; facti[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = (fact[i-1] * i) % m;
        // calc 1/n!
        long long &inv = facti[n], pw = fact[n];
        inv = 1;
        for (int e = mod-2; e > 0; e /= 2) {
            if (e&1) inv = inv * pw % mod;
            pw = pw * pw % mod;
        }
        for (int i = n-1; i > 0; i--) facti[i] = (facti[i+1] * (i+1)) % m;
    }

    ~ModComb() {
        if (fact) delete[] fact;
        if (facti) delete[] facti;
    }

    long long get(int n, int k) const {
        if (n < 0 || k < 0 || k > n) return 0;
        return fact[n] * facti[k] % mod * facti[n-k] % mod;
    }
};

int main() {
    int n, m, k; cin >> n >> m >> k;
    ModComb mc(n*m+1, M);
    long long comb = mc.get(n*m-2, k-2);
    long long ans = 0;
    for (int d = 1; d < n; d++) ans += (long long)m * m * d * (n - d);
    for (int d = 1; d < m; d++) ans += (long long)n * n * d * (m - d);
    ans %= M;
    cout << comb * ans % M << endl;
}
