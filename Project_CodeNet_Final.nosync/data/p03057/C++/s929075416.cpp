#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define ALL(c) (c).begin(), (c).end()

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

template <unsigned int MOD>
struct ModInt {
    using uint = unsigned int;
    using ull = unsigned long long;
    using M = ModInt;

    uint v;

    ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }
    M& set_norm(uint _v) {  //[0, MOD * 2)->[0, MOD)
        v = (_v < MOD) ? _v : _v - MOD;
        return *this;
    }

    explicit operator bool() const { return v != 0; }
    M operator+(const M& a) const { return M().set_norm(v + a.v); }
    M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }
    M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD); }
    M operator/(const M& a) const { return *this * a.inv(); }
    M& operator+=(const M& a) { return *this = *this + a; }
    M& operator-=(const M& a) { return *this = *this - a; }
    M& operator*=(const M& a) { return *this = *this * a; }
    M& operator/=(const M& a) { return *this = *this / a; }
    M operator-() const { return M() - *this; }
    M& operator++(int) { return *this = *this + 1; }
    M& operator--(int) { return *this = *this - 1; }

    M pow(ll n) const {
        if (n < 0) return inv().pow(-n);
        M x = *this, res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    M inv() const {
        ll a = v, b = MOD, p = 1, q = 0, t;
        while (b != 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(p -= t * q, q);
        }
        return M(p);
    }

    bool operator==(const M& a) const { return v == a.v; }
    bool operator!=(const M& a) const { return v != a.v; }
    friend ostream& operator<<(ostream& os, const M& a) { return os << a.v; }
    static uint get_mod() { return MOD; }
};

using Mint = ModInt<1000000007>;

Mint uni(int n) {
    V<Mint> dp(n + 1), prf(n + 1);
    dp[1] = prf[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = prf[i - 2];
        prf[i] = prf[i - 1] + dp[i];
    }
    Mint res(1);
    for (int l = 1; l <= n; l++) {
        res += dp[n - l] * (l + 1);
    }
    return res;
}

Mint solve(int n, int ml) {
    V<Mint> dp(n + 1), prf(n + 1);

    dp[1] = prf[1] = 1;

    for (int i = 2; i <= n; ++i) {
        prf[i] = prf[i - 1];
        if (i & 1) {
            dp[i] = prf[i - 1];
            if (i - ml - 1 > 0) {
                dp[i] -= prf[i - ml - 2];
            }
        }
        prf[i] += dp[i];
    }
    Mint res;
    for (int l = 1; l <= min(n, ml); l += 2) {
        res += dp[n - l] * (l + 1);
    }
    return res;
}

int main() {
    int N, M;
    string S;
    cin >> N >> M >> S;
    V<pii> vec;

    rep(i, M) {
        if (vec.size() > 0 && vec.back().fi == S[i]) {
            vec.back().se++;
        } else {
            vec.eb(S[i], 1);
        }
    }

    if (vec.size() == 1) {
        cout << uni(N) << endl;
        return 0;
    }

    if (N % 2) {
        puts("0");
        return 0;
    }

    if (vec.back().fi == vec[0].fi) {
        vec.pop_back();
    }

    debug(vec);

    int ml = vec[0].se;
    if (ml % 2 == 0) ml++;

    int sc = vec[0].fi;
    for (auto p : vec) {
        if (p.fi == sc && p.se % 2) {
            chmin(ml, p.se);
        }
    }
    debug(ml);

    cout << solve(N, ml) << endl;

    return 0;
}