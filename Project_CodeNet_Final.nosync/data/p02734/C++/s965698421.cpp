#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for(ll i=(ll)a; i<(ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
constexpr ll INF = 1LL<<60;

template<ll MOD>
struct modint {
    ll x;
    modint(): x(0) {}
    modint(ll y) : x(y>=0 ? y%MOD : y%MOD+MOD) {}
    static constexpr ll mod() { return MOD; }
    // e乗
    modint pow(ll e) {
        ll a = 1, p = x;
        while(e > 0) {
            if(e%2 == 0) {p = (p*p) % MOD; e /= 2;}
            else {a = (a*p) % MOD; e--;}
        }
        return modint(a);
    }
    modint inv() const {
        ll a=x, b=MOD, u=1, y=1, v=0, z=0;
        while(a) {
            ll q = b/a;
            swap(z -= q*u, u);
            swap(y -= q*v, v);
            swap(b -= q*a, a);
        }
        return z;
    }
    // Comparators
    bool operator <(modint b) { return x < b.x; }
    bool operator >(modint b) { return x > b.x; }
    bool operator<=(modint b) { return x <= b.x; }
    bool operator>=(modint b) { return x >= b.x; }
    bool operator!=(modint b) { return x != b.x; }
    bool operator==(modint b) { return x == b.x; }
    // Basic Operations
    modint operator+(modint r) const { return modint(*this) += r; }
    modint operator-(modint r) const { return modint(*this) -= r; }
    modint operator*(modint r) const { return modint(*this) *= r; }
    modint operator/(modint r) const { return modint(*this) /= r; }
    modint &operator+=(modint r) {
        if((x += r.x) >= MOD) x -= MOD;
        return *this;
    }
    modint &operator-=(modint r) {
        if((x -= r.x) < 0) x += MOD;
        return *this;
    }
    modint &operator*=(modint r) {
    #if !defined(_WIN32) || defined(_WIN64)
        x = (ll)x * r.x % MOD; return *this;
    #endif
        unsigned long long y = (unsigned long long)x * r.x;
        unsigned xh = (unsigned) (y >> 32), xl = (unsigned) y, d, m;
        asm(
            "divl %4; \n\t"
            : "=a" (d), "=d" (m)
            : "d" (xh), "a" (xl), "r" (MOD)
        );
        x = m;
        return *this;
    }
    modint &operator/=(modint r) { return *this *= r.inv(); }
    // increment, decrement
    modint operator++() { x++; return *this; }
    modint operator++(signed) { modint t = *this; x++; return t; }
    modint operator--() { x--; return *this; }
    modint operator--(signed) { modint t = *this; x--; return t; }
    // 平方剰余のうち一つを返す なければ-1
    friend modint sqrt(modint a) {
        if(a == 0) return 0;
        ll q = MOD-1, s = 0;
        while((q&1)==0) q>>=1, s++;
        modint z=2;
        while(1) {
            if(z.pow((MOD-1)/2) == MOD-1) break;
            z++;
        }
        modint c = z.pow(q), r = a.pow((q+1)/2), t = a.pow(q);
        ll m = s;
        while(t.x>1) {
            modint tp=t;
            ll k=-1;
            FOR(i, 1, m) {
                tp *= tp;
                if(tp == 1) { k=i; break; }
            }
            if(k==-1) return -1;
            modint cp=c;
            REP(i, m-k-1) cp *= cp;
            c = cp*cp, t = c*t, r = cp*r, m = k;
        }
        return r.x;
    }

    template<class T>
    friend modint operator*(T l, modint r) { return modint(l) *= r; }
    template<class T>
    friend modint operator+(T l, modint r) { return modint(l) += r; }
    template<class T>
    friend modint operator-(T l, modint r) { return modint(l) -= r; }
    template<class T>
    friend modint operator/(T l, modint r) { return modint(l) /= r; }
    template<class T>
    friend bool operator==(T l, modint r) { return modint(l) == r; }
    template<class T>
    friend bool operator!=(T l, modint r) { return modint(l) != r; }
    // Input/Output
    friend ostream &operator<<(ostream& os, modint a) { return os << a.x; }
    friend istream &operator>>(istream& is, modint &a) { 
        is >> a.x;
        a.x = ((a.x%MOD)+MOD)%MOD;
        return is;
    }
    friend string to_frac(modint v) {
        static map<ll, PII> mp;
        if(mp.empty()) {
            mp[0] = mp[MOD] = {0, 1};
            FOR(i, 2, 1001) FOR(j, 1, i) if(__gcd(i, j) == 1) {
                mp[(modint(i) / j).x] = {i, j};
            }
        }
        auto itr = mp.lower_bound(v.x);
        if(itr != mp.begin() && v.x - prev(itr)->first < itr->first - v.x) --itr;
        string ret = to_string(itr->second.first + itr->second.second * ((int)v.x - itr->first));
        if(itr->second.second > 1) {
            ret += '/';
            ret += to_string(itr->second.second);
        }
        return ret;
    }
};
using mint = modint<998244353>;

int main() {
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];

    mint ans = 0;
    vector<vector<mint>> dp(n+1, vector<mint>(s));
    REP(i, n+1) dp[i][0] = i+1;
    REP(i, n) REP(j, s) {
        if(j) dp[i+1][j] += dp[i][j];
        if(j+a[i]<s) {
            if(j==0) dp[i+1][j+a[i]] += i+1;
            else dp[i+1][j+a[i]] += dp[i][j];
        } else if(j+a[i]==s) {
            ans += dp[i][j] * (n-i);
            dump(i, ans);
        }
    }
    cout << ans << endl;

    return 0;
}
