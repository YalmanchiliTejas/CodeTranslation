#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define all(x) begin(x), end(x)
#define uniq(x) (x).erase(unique(all(x)), end(x))
#define bit(n) (1LL << (n))
#define dump(x) cerr << #x " = " << (x) << endl
using vint = vector<int>;
using vvint = vector<vint>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr double pi = 3.1415926535897932384626433832795028L;
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int gcd(int a, int b) {
    while (b) { swap(a %= b, b); }
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<typename T> void fin(T mes) {
    cout << mes << endl;
    exit(0);
}
template<typename T, typename U> bool chmax(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> bool chmin(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &rhs) {
    os << "(" << rhs.first << ", " << rhs.second << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
struct setup {
    static constexpr int PREC = 20;
    setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    };
} setup;

template<int MOD = 1000000007>
struct mod_int {
    int val;
    mod_int(long long val_ = 0) : val(val_ >= 0 ? val_ % MOD : (MOD - (-val_) % MOD) % MOD) {}
    bool operator==(const mod_int &rhs) const { return val == rhs.val; }
    bool operator!=(const mod_int &rhs) const { return std::rel_ops::operator!=(*this, rhs); }
    mod_int &operator+=(const mod_int &rhs) {
        if ((val += rhs.val) >= MOD) { val -= MOD; }
        return *this;
    }
    mod_int &operator-=(const mod_int &rhs) {
        if ((val += MOD - rhs.val) >= MOD) { val -= MOD; }
        return *this;
    }
    mod_int &operator*=(const mod_int &rhs) {
        val = (int) ((long long) val * rhs.val % MOD);
        return *this;
    }
    mod_int &operator/=(const mod_int &rhs) { return *this *= rhs.inv(); }
    mod_int operator+() const { return *this; }
    mod_int operator-() const { return mod_int(-val); }
    mod_int operator++() { return *this += 1; }
    mod_int operator--() { return *this -= 1; }
    mod_int operator++(signed) {
        const mod_int ret(*this);
        ++*this;
        return ret;
    }
    mod_int operator--(signed) {
        const mod_int ret(*this);
        --*this;
        return ret;
    }
    mod_int operator+(const mod_int &rhs) const { return mod_int(*this) += rhs; }
    mod_int operator-(const mod_int &rhs) const { return mod_int(*this) -= rhs; }
    mod_int operator*(const mod_int &rhs) const { return mod_int(*this) *= rhs; }
    mod_int operator/(const mod_int &rhs) const { return mod_int(*this) /= rhs; }
    mod_int inv() const {
        int a = MOD, b = val, u = 0, v = 1;
        while (b) {
            int t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return mod_int(u);
    }
    mod_int pow(long long n) const {
        if (n < 0) { return pow(-n).inv(); }
        mod_int ret = 1, mul = *this;
        while (n) {
            if (n & 1) { ret *= mul; }
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend std::istream &operator>>(std::istream &is, mod_int &rhs) {
        long long v;
        is >> v;
        rhs = v;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const mod_int &rhs) { return os << rhs.val; }
    struct combination {
        std::vector<mod_int> fact{1, 1}, f_inv{1, 1}, inv{0, 1};
        void calc(int n) {
            while (fact.size() <= n) {
                int i = fact.size();
                fact.push_back(fact[i - 1] * i);
                inv.push_back(-inv[MOD % i] * (MOD / i));
                f_inv.push_back(f_inv[i - 1] * inv[i]);
            }
        }
        mod_int P(int n, int r) { return r < 0 || n < r ? 0 : (calc(n), fact[n] * f_inv[n - r]); }
        mod_int C(int n, int r) { return r < 0 || n < r ? 0 : (calc(n), fact[n] * f_inv[r] * f_inv[n - r]); }
        mod_int H(int n, int r) { return C(n + r - 1, r); }
    };
};

using mint=mod_int<998244353>;
int N, S;
int A[3300];
mint dp[3300][3300];
signed main() {
    cin >> N >> S;
    rep(i, N) { cin >> A[i]; }
    mint ans = 0;
    rep(i, N) {
        if (A[i] <= S) { dp[i + 1][A[i]] += i + 1; }
        reps(j, S) {
            dp[i + 1][j] += dp[i][j];
            if (j + A[i] <= S) { dp[i + 1][j + A[i]] += dp[i][j]; }
        }
        ans += dp[i + 1][S];
    }
    cout << ans << endl;
}
