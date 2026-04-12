#include<bits/stdc++.h>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

const int mod = 1000000007;
const int FacN = 200200;//使わないなら0

constexpr int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)res *= a;
        a *= a;
        res %= mod;
        a %= mod;
        b /= 2;
    }
    return res;
}

constexpr int inv(int x) {
    return power(x, mod - 2);
}

const struct Fac {
    int val[FacN];

    constexpr Fac() : val() {
        if (FacN == 0)return;
        val[0] = 1;
        for (int i = 1; i < FacN; ++i) val[i] = val[i - 1] * i % mod;
    }

    const int &operator[](size_t i) const {
        return val[i];
    }
} fac;

const struct FacInv {
    int val[FacN];

    constexpr FacInv() : val() {
        if (FacN == 0)return;
        val[FacN - 1] = 1;
        for (int i = 1; i < FacN; ++i)val[FacN - 1] = val[FacN - 1] * i % mod;
        val[FacN - 1] = inv(val[FacN - 1]);
        for (int i = FacN - 1; i >= 1; --i)val[i - 1] = val[i] * i % mod;
    }

    const int &operator[](size_t i) const {
        return val[i];
    }
} fac_inv;

int Perm(int n, int r) {
    if (n < r) return 0;
    return fac[n] * fac_inv[n - r] % mod;
}

int Comb(int n, int r) {
    return Perm(n, r) * fac_inv[r] % mod;
}
//mod,Factorial書き換え
//要検証

int N, M, K;


signed main() {
    cin >> N >> M >> K;
    int ans = 0;
    //X
    for (int d = 1; d <= M - 1; ++d) {
        ans += d * (M - d) * N * N % mod * Comb(N * M - 2, K - 2);
        ans %= mod;
    }
    //Y
    for (int d = 1; d <= N - 1; ++d) {
        ans += d * (N - d) * M * M % mod * Comb(N * M - 2, K - 2);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
