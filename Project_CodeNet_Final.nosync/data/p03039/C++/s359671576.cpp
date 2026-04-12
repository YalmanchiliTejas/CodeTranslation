#include <bits/stdc++.h>

using namespace std;
using ll = long long;
// #define int ll
using PII = pair<ll, ll>;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()

template<typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template<typename T> bool IN(T a, T b, T x) { return a<=x&&x<b; }
template<typename T> T ceil(T a, T b) { return a/b + !!(a%b); }

template<typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type
fill_v(T &t, const V &v) { t=v; }
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t, const V &v ) { for(auto &e:t) fill_v(e,v); }

template<class S,class T>
ostream &operator <<(ostream& out,const pair<S,T>& a) {
    out<<'('<<a.first<<','<<a.second<<')'; return out;
}
template<class T>
ostream &operator <<(ostream& out,const vector<T>& a){
    out<<'[';
    for(const T &i: a) out<<i<<',';
    out<<']';
    return out;
}
template<class T>
ostream &operator <<(ostream& out, const set<T>& a) {
    out<<'{';
    for(const T &i: a) out<<i<<',';
    out<<'}';
    return out;
}
template<class T, class S>
ostream &operator <<(ostream& out, const map<T,S>& a) {
    out<<'{';
    for(auto &i: a) out<<i<<',';
    out<<'}';
    return out;
}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}; // DRUL
const int INF = 1<<30;
const ll LLINF = 1LL<<60;
const ll MOD = 1000000007;

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
        x = x * r.x % MOD; return *this;
    #endif
        unsigned long long y = x * r.x;
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
};
using mint = modint<1000000007>;
template<class T> mint operator*(T l, mint r) { return mint(l) *= r; }
template<class T> mint operator+(T l, mint r) { return mint(l) += r; }
template<class T> mint operator-(T l, mint r) { return mint(l) -= r; }
template<class T> mint operator/(T l, mint r) { return mint(l) /= r; }
template<class T> bool operator==(T l, mint r) { return mint(l) == r; }
template<class T> bool operator!=(T l, mint r) { return mint(l) != r; }
// Input/Output
ostream &operator<<(ostream& os, mint a) { return os << a.x; }
istream &operator>>(istream& is, mint &a) { return is >> a.x; }
string to_frac(mint v) {
    static map<ll, PII> mp;
    if(mp.empty()) {
        mp[0] = mp[mint::mod()] = {0, 1};
        FOR(i, 2, 1001) FOR(j, 1, i) if(__gcd(i, j) == 1) {
            mp[(mint(i) / j).x] = {i, j};
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

// 前計算O(N) クエリO(1)
mint combi(ll N, ll K) {
    const int maxN=5e5; // !!!
    static mint fact[maxN+1]={},factr[maxN+1]={};
    if (fact[0]==0) {
        fact[0] = factr[0] = 1;
        FOR(i, 1, maxN+1) fact[i] = fact[i-1] * i;
        factr[maxN] = fact[maxN].inv();
        for(ll i=maxN-1; i>=0; --i) factr[i] = factr[i+1] * (i+1);
    }
    if(K<0 || K>N) return 0; // !!!
    return factr[K]*fact[N]*factr[N-K];
}

// 前計算O(Klog(mod)) クエリO(K)
mint combi_bigN(ll N, ll K) {
    const int maxN=5e5; // !!!
    static mint inv[maxN+1] = {};
    if(inv[0]==0) {
        inv[0] = 1;
        FOR(i, 1, maxN+1) inv[i] = mint(i).inv();
    }
    if(K<0 || K>N) return 0; // !!!
    mint ret = 1;
    for(;K>0;N--,K--) ret *= N, ret *= inv[K];
    return ret;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll h, w, k;
    cin >> h >> w >> k;

    mint mh(h), mw(w), ret = 0;
    FOR(i, 1, w) {
        ret += i * mh * mh * (mw-i) * combi(h*w-2, k-2);
        // cout << "i=" << i << " ret=" << ret << endl;
    }
    FOR(i, 1, h) {
        ret += i * mw * mw * (mh-i) * combi(h*w-2, k-2);
        // cout << "i=" << i << " ret=" << ret << endl;
    }

    cout << ret << endl;

    return 0;
}
