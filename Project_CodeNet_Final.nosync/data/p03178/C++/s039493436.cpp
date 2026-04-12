#include <bits/stdc++.h>
using namespace std;

#ifdef _LOCAL_DEBUG
#define en_if typename enable_if<sizeof x<T>(0) == 4, ostream&>::type
namespace dbg {
template<class T> char x(...); 
template<class T> auto x(T* v) -> decltype(v->size(), 0); 
template<class T> auto x(T* v) -> decltype(v->c_str(), "");
template<class T> en_if operator<<(ostream& os, const T& v) { 
    os << "["; const char* sep = ""; 
    for(const auto& x : v) os << sep << x, sep = ", ";
    return os << "]";
}
template<class F, class S> 
ostream& operator<<(ostream& os, const pair<F, S>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template<class T> 
void print(const char* n, T e) { cerr << "[" << n << ": " << e << "]\n"; }
template<class Head, class... Tail> 
void print(const char* n, Head h, Tail... t) {
    cerr << "["; while(*n != ',') cerr << *n++; cerr << ": " << h << "] ";
    print(n + 2, t...); 
}}
#define debug(...) dbg::print(#__VA_ARGS__, __VA_ARGS__);
#else
#define debug(...)
#endif

template<int MOD_> struct modnum {
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");

private:
    using ll = long long;
    int v;
    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }

public:
    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD)) {
        if (v < 0)
            v += MOD;
    }
    explicit operator int() const { return v; }
    friend ostream& operator<<(ostream& out, const modnum& n) {
        return out << int(n);
    }
    friend istream& operator>>(istream& in, modnum& n) {
        ll v_;
        in >> v_;
        n = modnum(v_);
        return in;
    }

    friend bool operator==(const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator!=(const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum inv() const {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    friend modnum inv(const modnum& m) { return m.inv(); }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD - v : 0;
        return res;
    }
    friend modnum neg(const modnum& m) { return m.neg(); }

    modnum operator-() const { return neg(); }
    modnum operator+() const { return modnum(*this); }
    modnum& operator++() {
        v++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator--() {
        if (v == 0) v = MOD;
        v--;
        return *this;
    }
    modnum& operator+=(const modnum& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    modnum& operator-=(const modnum& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    modnum& operator*=(const modnum& o) { v = int(ll(v) * ll(o.v) % MOD); return *this; }
    modnum& operator/=(const modnum& o) { return *this *= o.inv(); }

    friend modnum operator++(modnum& a, int) { modnum r = a; ++a; return r; }
    friend modnum operator--(modnum& a, int) { modnum r = a; --a; return r; }
    friend modnum operator+(const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator-(const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator*(const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator/(const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    using mint = modnum<1000000007>;
    string k_str;
    int d;
    cin >> k_str >> d;
    int n = k_str.size();
    vector<int> k(n);
    for (int i = n - 1; i >= 0; i--)
        k[n - i - 1] = k_str[i] - '0';
    int digitsum = accumulate(k.begin(), k.end(), 0);
    mint answer = digitsum % d == 0 ? 0 : -1;
    vector<vector<mint>> dp(2, vector<mint>(d));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        digitsum -= k[i];
        fill(dp[1].begin(), dp[1].end(), 0);
        for (int j = 0; j < d; j++) {
            for (int x = 0; x <= 9; x++) {
                dp[1][(j + x) % d] += dp[0][j];
                if (x < k[i] && (digitsum + x + j) % d == 0)  {
                    answer += dp[0][j];
                }
            }
        }
        dp[0] = dp[1];
    }
    cout << answer << '\n';
    return 0;
}