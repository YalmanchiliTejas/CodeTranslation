class in{struct It{int it;const bool rev;explicit constexpr It(int it_, bool rev=false):it(it_),rev(rev){}int operator*(){return it;}bool operator!=(It& r){return it!=r.it;}void operator++(){rev?--it:++it;}};const It i,n;public:explicit constexpr in(int n):i(0),n(n<0?0:n){}explicit constexpr in(int i,int n):i(i,n<i),n(n){}const It& begin(){return i;}const It& end(){return n;}};

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 MOD = 1e9 + 7;
i64 comb[1010][1010];
void setComb(const int n = 1010) {
    comb[0][0] = 1;
    for(int i : in(1, n)) {
        comb[i][0] = 1;
        for(int j : in(1, i + 1))
          comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
    }
}
template<typename T>
T mod_pow(T x, T n, const T mod) {
    T res = 1;
    for(; n > 0; n >>= 1) {
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

template <typename T>
T mod_inv(T x, T mod) {
    return mod_pow(x, mod - 2, mod);
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    setComb();
    vector<i64> dp(n + 1, 0LL);
    auto dp_ = dp;
    dp[0] = 1LL;
    for(int i : in(a, b + 1)) {
        dp_ = dp;
        for(int j : in(n + 1)) {
            if(dp[j] == 0) continue;
            int rest = n - j, val = 0;
            i64 tcom = 1LL;
            for(int k : in(d)) {
                if(rest < i) break;
                (tcom *= comb[rest][i]) %= MOD;
                (tcom *= mod_inv((i64)(k + 1), MOD)) %= MOD;
                rest -= i;
                val += i;
                if(k < c - 1) continue;
                (dp_[j + val] += dp[j] * tcom) %= MOD;
            }
        }
        dp = dp_;
    }
    cout << dp[n] << endl;
    return 0;
}