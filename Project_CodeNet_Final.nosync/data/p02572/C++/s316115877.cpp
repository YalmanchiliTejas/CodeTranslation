#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define RFOR(i,a,b) for(int i=(b-1); i>=(a); i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define pb push_back
using ll = long long;
using D = double;
using LD = long double;
using P = pair<int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template<int mod> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % mod) {
        if (val < 0) val += mod;
    }
    constexpr int getmod() { return mod; }
    constexpr Fp operator - () const noexcept {
        return val ? mod - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += mod;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % mod;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = mod, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % mod;
        if (val < 0) val += mod;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr istream& operator >> (istream &is, const Fp<mod>& x) noexcept {
        int val; is >> val;
        x = Fp<mod>(val);
        return is;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<mod>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<mod> modpow(const Fp<mod> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

const int mod = 1e9+7;
using mint = Fp<mod>;

int main(){
    int n; cin  >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<mint> sum(n);
    sum[n-1] = (mint)a[n-1];
    rrep(i,n-1){
        sum[i] = sum[i+1] + (mint)a[i];
    }
    mint ans = 0;
    rep(i,n-1){
        ans += (mint)a[i] * sum[i+1];
    }
    cout << ans << endl;
}
