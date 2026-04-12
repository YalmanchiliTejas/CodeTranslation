#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<n; ++i)
#define rep1(i,n) for(ll i=1; i<=n; ++i)
#define revrep(i,n) for(ll i=n-1; n>=0; --i)
inline constexpr ll Inf = (1ULL << 62) -1;

template <ll Mod>
class modint {
    public:
    ll n=0;
    modint(){}
    modint(ll n):n(n){ clamp(); }
    modint& operator = (modint const& a) = default;
    modint& operator = (int a) { n = a; clamp(); return *this; }
    modint operator - () { modint t = *this; t.n = -t.n; t.clamp(); return t; }
    modint& operator *= (modint const& a) { n *= a.n; clamp(); return *this; }
    modint& operator *= (ll const& a) { n *= a; clamp(); return *this; }
    modint& operator += (modint const& a) { n += a.n; clamp(); return *this; }
    modint& operator %= (modint const& a) { n %= a.n; clamp(); return *this; }
    friend modint operator * (modint a, modint b) { modint t(a); t.n *= b.n; t.clamp(); return t; }
    friend modint operator + (modint a, modint b) { modint t(a); t.n += b.n; t.clamp(); return t; }
    friend modint operator - (modint a, modint b) { modint t(a); t.n -= b.n; t.clamp(); return t; }
    friend ostream& operator << (ostream& os, modint const& a) { os << a.n; return os; }
    friend bool operator == (modint const& a, int b) { return a.n == b; }
    void clamp() { n %= Mod; if (n < 0) n += Mod; }
    modint& inv() { return pow(Mod-2); }
    ll get() { return n; }
    modint& pow(ll p) {
        ll a=1, e=n;
        while (p > 0) {
            if (p&1) { a *= e; a %= Mod; }
            e *= e; e %= Mod; p >>= 1;
        }
        n = a; clamp();
        return *this;
    }
};
const ll Mod = 1e9+7;
using mint = modint<Mod>;

int main() {
    ll ans=0, N;
    cin >> N;
    vector<ll> a(N+1);
    rep1(i,N) cin >> a[i];
    mint x,d;
    rep1(i,N) {
        x += a[i];
        d += a[i]*a[i];
    }
    ans = ((x * x - d) * mint(2).inv()).get();
    cout << ans << endl;
}
