#include <bits/stdc++.h>
using namespace std;

template <int M, bool IsPrime = false>
class modulo {
    using ll = long long;
public:
    modulo() : n(0) {}
    modulo(int m) : n(m) {
        if(n >= M) {
            n %= M;
        } else if(n < 0) {
            n = (n % M + M) % M;
        }
    }
    modulo(ll m) {
        if(m >= M) {
            m %= M;
        } else if(m < 0) {
            m = (m % M + M) % M;
        }
        n = m;
    }

    explicit operator int() const {
        return n;
    }
    explicit operator ll() const {
        return n;
    }
    bool operator==(modulo const& a) const {
        return n == a.n;
    }

    modulo& operator+=(modulo const& a) {
        n += a.n;
        if(n >= M) {
            n -= M;
        }
        return *this;
    }
    modulo& operator-=(modulo const& a) {
        n -= a.n;
        if(n < 0) {
            n += M;
        }
        return *this;
    }
    modulo& operator*=(modulo const& a) {
        n = (ll(n) * a.n) % M;
        return *this;
    }
    modulo operator^(int n) const {
        if(n == 0) {
            return modulo(1);
        }
        const modulo a = *this;
        modulo res = (a * a) ^ (n / 2);
        return n % 2 ? res * a : res;
    }

    // for C++11, enable_if_t -> typename enable_if::type
    typename std::enable_if<IsPrime, modulo>::type operator/(modulo const& a) const {
        return *this * modulo(inv(ll(a), M));
    }

private:
    ll n;
    static typename std::enable_if<IsPrime, ll>::type inv(ll a, ll p) {
        return (a == 1 ? 1 : (1 - p*inv(p%a, a))/a + p);
    }
};

template <int M, bool IsPrime>
modulo<M, IsPrime> operator+(modulo<M, IsPrime> lhs, modulo<M, IsPrime> const& rhs) {
    lhs += rhs;
    return lhs;
}
template <int M, bool IsPrime>
modulo<M, IsPrime> operator-(modulo<M, IsPrime> lhs, modulo<M, IsPrime> const& rhs) {
    lhs -= rhs;
    return lhs;
}
template <int M, bool IsPrime>
modulo<M, IsPrime> operator*(modulo<M, IsPrime> lhs, modulo<M, IsPrime> const& rhs) {
    lhs *= rhs;
    return lhs;
}

// sw == false -> inv
template <int M>
modulo<M, true> fact(int n, bool sw = true) {
    static std::vector<modulo<M, true>> v1 = {1}, v2 = {1};
    if(n >= (int)v1.size()) {
        const int from = v1.size(), to = n + 1024;
        v1.reserve(to);
        v2.reserve(to);
        for(int i=from; i<to; ++i) {
            v1.push_back(v1.back() * modulo<M, true>(i));
            v2.push_back(v2.back() / modulo<M, true>(i));
        }
    }
    return sw ? v1[n] : v2[n];
}

template <int M>
modulo<M, true> comb(int a, int b) {
    if(b < 0 || b > a) {
        return fact<M>(0);
    }
    return fact<M>(a, true) * fact<M>(b, false) * fact<M>(a-b, false);
}


const int MOD = 1000000007;
using mod = modulo<MOD, true>;

int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    vector<vector<mod>> dp(B + 2, vector<mod>(N + 1));
    dp[A][N] = 1;
    for(int i = A; i <= B; ++i) {
        for(int j = 0; j <= N; ++j) {
            if(dp[i][j] == 0) {
                continue;
            }
            mod t = dp[i][j];
            for(int use = 0; use * i <= j; ++use) {
                if(use == 0 || C <= use && use <= D) {
                    dp[i + 1][j - use * i] += t * fact<MOD>(use, false);
                }
                t *= comb<MOD>(j - use * i, i);
            }
        }
    }

    cout << (int)dp[B + 1][0] << endl;
}


