#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define bit(n) (1LL << (n))
#define dump(x) cerr << #x " = " << (x) << endl
using vint=vector<int>;
using vvint=vector<vint>;
using pint=pair<int, int>;
using vpint=vector<pint>;
template<typename T> using priority_queue_rev=priority_queue<T, vector<T>, greater<T>>;
constexpr double pi = 3.1415926535897932384626433832795028;
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int gcd(int a, int b) {
    while (b) { swap(a %= b, b); }
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<typename T1, typename T2> bool chmax(T1 &a, const T2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T1, typename T2> bool chmin(T1 &a, const T2 &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &rhs) {
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
struct Setup {
    static constexpr int PREC = 20;
    Setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    };
} setup;

template<int MOD = 1000000007>
struct ModInt {
    int val;
    ModInt(long long val_ = 0) : val(val_ >= 0 ? val_ % MOD : (MOD - (-val_) % MOD) % MOD) {}
    bool operator==(const ModInt &rhs) const { return val == rhs.val; }
    bool operator!=(const ModInt &rhs) const { return std::rel_ops::operator!=(*this, rhs); }
    ModInt &operator+=(const ModInt &rhs) {
        if ((val += rhs.val) >= MOD) { val -= MOD; }
        return *this;
    }
    ModInt &operator-=(const ModInt &rhs) {
        if ((val += MOD - rhs.val) >= MOD) { val -= MOD; }
        return *this;
    }
    ModInt &operator*=(const ModInt &rhs) {
        val = (int) ((long long) val * rhs.val % MOD);
        return *this;
    }
    ModInt &operator/=(const ModInt &rhs) { return *this *= rhs.inv(); }
    ModInt operator+() const { return *this; }
    ModInt operator-() const { return ModInt(-val); }
    ModInt operator++() { return *this += 1; }
    ModInt operator--() { return *this -= 1; }
    ModInt operator++(signed) {
        const ModInt ret(*this);
        ++*this;
        return ret;
    }
    ModInt operator--(signed) {
        const ModInt ret(*this);
        --*this;
        return ret;
    }
    ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs; }
    ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs; }
    ModInt inv() const {
        int a = MOD, b = val, u = 0, v = 1;
        while (b > 0) {
            int t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    ModInt pow(long long n) const {
        if (n < 0) { return pow(-n).inv(); }
        ModInt ret = 1, mul = *this;
        while (n > 0) {
            if (n & 1) { ret *= mul; }
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend std::istream &operator>>(std::istream &is, ModInt &rhs) {
        long long v;
        is >> v;
        rhs = v;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const ModInt &rhs) { return os << rhs.val; }
    struct Combination {
        std::vector<ModInt> fact{1, 1}, fInv{1, 1}, inv{0, 1};
        void calc(int n) {
            while (fact.size() <= n) {
                int i = fact.size();
                fact.push_back(fact[i - 1] * i);
                inv.push_back(-inv[MOD % i] * (MOD / i));
                fInv.push_back(fInv[i - 1] * inv[i]);
            }
        }
        ModInt P(int n, int r) { return r < 0 || n < r ? 0 : (calc(n), fact[n] * fInv[n - r]); }
        ModInt C(int n, int r) { return r < 0 || n < r ? 0 : (calc(n), fact[n] * fInv[r] * fInv[n - r]); }
        ModInt H(int n, int r) { return C(n + r - 1, r); }
    };
};
using Mint=ModInt<998244353>;
int N;
signed main() {
    cin >> N;
    Mint ans = Mint(3).pow(N);
    Mint::Combination comb;
    for (int i = N / 2 + 1; i <= N; i++) {
        ans -= comb.C(N, i) * Mint(2).pow(N - i) * 2;
    }
    cout << ans << endl;
}
