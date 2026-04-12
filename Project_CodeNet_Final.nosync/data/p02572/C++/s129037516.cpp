#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

template<int mod>
class ModInt {
    private:
        long long val;
    public:
        constexpr ModInt(const long long v = 0) : val(v%mod) { if (val < 0) val += mod; }
        constexpr ModInt(const ModInt &v) : val(v.val) {}
        constexpr ModInt &operator=(const long long v) { val = v; return *this; }
        constexpr ModInt &operator=(const ModInt &v) { if (this != &v) val = v.val; return *this; }
        constexpr ModInt operator+() const { return ModInt(val); }
        constexpr ModInt operator-() const { return ModInt(-val); }
        constexpr ModInt operator+(const ModInt &v) const { return ModInt(*this) += v; }
        constexpr ModInt operator-(const ModInt &v) const { return ModInt(*this) -= v; }
        constexpr ModInt operator*(const ModInt &v) const { return ModInt(*this) *= v; }
        constexpr ModInt operator/(const ModInt &v) const { return ModInt(*this) /= v; }
        constexpr ModInt &operator+=(const ModInt &v) { val += v.val; if (val >= mod) val -= mod; return *this; }
        constexpr ModInt &operator-=(const ModInt &v) { val -= v.val; if (val < 0) val += mod; return *this; }
        constexpr ModInt &operator*=(const ModInt &v) { val *= v.val; if (val >= mod) val %= mod; return *this; }
        constexpr ModInt &operator/=(const ModInt &v) { val *= v.inverse().val; if (val >= mod) val %= mod; return *this; }
        constexpr ModInt &operator++() { ++val; if (val >= mod) val -= mod; return *this; }
        constexpr ModInt &operator--() { --val; if (val < 0) val += mod; return *this; }
        constexpr ModInt operator++(int) { ModInt tmp(*this); operator++(); return tmp; }
        constexpr ModInt operator--(int) { ModInt tmp(*this); operator--(); return tmp; }
        constexpr bool operator==(const ModInt &v) const { return val == v.val; }
        constexpr bool operator!=(const ModInt &v) const { return !(*this == v); }
        friend std::istream &operator>>(std::istream &s, ModInt &v) { long long tmp; s >> tmp; v = ModInt(tmp); return s; }
        friend std::ostream &operator<<(std::ostream &s, const ModInt &v) { return s << v.val; }
        constexpr ModInt inverse() const {
            long long n = val, res = 1;
            while (n > 1) {
                res *= (mod - mod / n);
                res %= mod;
                n = mod % n;
            }
            return ModInt(res);
        }
        static constexpr ModInt pow(ModInt v, long long n) {
            ModInt res(1);
            for ( ; n>0; n>>=1) {
                if (n & 1) res *= v;
                v *= v;
            }
            return res;
        }
};

using MInt = ModInt<MOD>;

void solve() {
    int N;
    cin >> N;
    vector<MInt> A(N);
    for (int i=0; i<N; ++i) cin >> A[i];

    vector<MInt> sum(N);
    sum[0] = A[0];
    for (int i=1; i<N; ++i) sum[i] = sum[i-1] + A[i];
    MInt ans = 0;
    for (int i=1; i<N; ++i) ans += A[i] * sum[i-1];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
