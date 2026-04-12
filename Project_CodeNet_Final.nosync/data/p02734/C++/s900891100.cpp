#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tp3 = tuple<int, int, int>;
using Mat = vector<vector<ll>>;
constexpr int INF = 1 << 28;
constexpr ll INFL = 1ll << 60;
constexpr int dh[4] = { 0,1,0,-1 };
constexpr int dw[4] = { -1,0,1,0 };
bool isin(const int H, const int W, const int h, const int w) {
    return 0 <= h && h < H && 0 <= w && w < W;
}
template<typename T>
T minch(T& l, T r) {
    return l = min(l, r);
}
template<typename T>
T maxch(T& l, T r) {
    return l = max(l, r);
}
template<typename T>
void output(const T& val) {
    cout << val << endl;
}
template<typename T>
void output(const vector<T>& vec, const bool newline = false) {
    for (const T& val : vec)cout << val << (newline ? '\n' : ' '); cout << endl;
}
template<typename T>
void output(const vector<vector<T>>& mat) {
    for (const auto& row : mat)output(row);
}
struct ModInt {
    static const ll MOD = 998244353;

    // constructors etc
    ModInt() :num(1ll) {}
    ModInt(ll num_) :num(num_%MOD) {}
    ModInt(const ModInt& modint) :num(modint.num%MOD) {}
    ll get()const { return num; }

    // operator etc
    // operator ll() const { return num; }
    // ll operator*() { return num; }
    ModInt& operator+=(const ModInt& r) { (num += r.num) %= MOD; return *this; }
    ModInt& operator-=(const ModInt& r) { (num += -r.num + MOD) %= MOD; return *this; }
    ModInt& operator*=(const ModInt& r) { (num *= r.num) %= MOD; return *this; }
    ModInt& operator/=(const ModInt& r) { (num *= r.inv().num) %= MOD; return *this; }
    ModInt pow(const ModInt& r)const {
        ll res = 1;
        ll x = num;
        ll n = r.num;
        while (n > 0) {
            if (n & 1)res = (res*x) % MOD;
            x = (x*x) % MOD;
            n >>= 1;
        }
        return res;
    }
    ModInt inv()const { return this->pow(MOD - 2); }

    ModInt operator+(const ModInt& r)const { return ModInt(*this) += r; }
    ModInt operator-(const ModInt& r)const { return ModInt(*this) -= r; }
    ModInt operator*(const ModInt& r)const { return ModInt(*this) *= r; }
    ModInt operator/(const ModInt& r)const { return ModInt(*this) /= r; }
    ModInt operator+(const ll& r)const { return *this + ModInt(r); }
    ModInt operator-(const ll& r)const { return *this - ModInt(r); }
    ModInt operator*(const ll& r)const { return *this * ModInt(r); }
    ModInt operator/(const ll& r)const { return *this / ModInt(r); }

private:
    ll num;
};
ostream& operator<<(ostream& stream, const ModInt& val) { stream << val.get(); return stream; }

// ============ template finished ============

int main()
{
    ll N, S;
    cin >> N >> S;
    vector<ll> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    vector<vector<ModInt>> dp(N + 1, vector<ModInt>(S + 1, 0));
    rep(i, N) {
        ll offset = A[i];
        for (ll j = S - offset; j >= 0; j--) {
            dp[i + 1][j + offset] += dp[i][j];
        }
        rep(j, S)dp[i + 1][j] += dp[i][j];
        if (offset <= S) dp[i + 1][offset] += i + 1;
    }
    ModInt res(0);
    rep(i, N) {
        auto l = dp[N - i].back();
        auto r = (i + 1);
        res += l * r;
    }
    cout << res << endl;
    return 0;
}
