#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include "bits/stdc++.h" // define macro "/D__MAI"

using namespace std;
typedef long long int ll;

#define xprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#define debugv(v) {printf("L%d %s > ",__LINE__,#v);for(auto e:v){cout<<e<<" ";}cout<<endl;}
#define debuga(m,w) {printf("L%d %s > ",__LINE__,#m);for(int x=0;x<(w);x++){cout<<(m)[x]<<" ";}cout<<endl;}
#define debugaa(m,h,w) {printf("L%d %s >\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){cout<<(m)[y][x]<<" ";}cout<<endl;}}
#define ALL(v) (v).begin(),(v).end()
#define repeat(cnt,l) for(auto cnt=0ll;(cnt)<(l);++(cnt))
#define iterate(cnt,b,e) for(auto cnt=(b);(cnt)!=(e);++(cnt))
#define MD 1000000007ll
#define PI 3.1415926535897932384626433832795
#define EPS 1e-12
template<typename T1, typename T2> ostream& operator <<(ostream &o, const pair<T1, T2> p) { o << "(" << p.first << ":" << p.second << ")"; return o; }
template<typename iterator> inline size_t argmin(iterator begin, iterator end) { return distance(begin, min_element(begin, end)); }
template<typename iterator> inline size_t argmax(iterator begin, iterator end) { return distance(begin, max_element(begin, end)); }
template<typename T> T& maxset(T& to, const T& val) { return to = max(to, val); }
template<typename T> T& minset(T& to, const T& val) { return to = min(to, val); }
void bye(string s, int code = 0) { cout << s << endl; exit(0); }
mt19937_64 randdev(8901016);
inline ll rand_range(ll l, ll h) {
    return uniform_int_distribution<ll>(l, h)(randdev);
}

#ifdef __MAI
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
#ifdef __VSCC
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
namespace {
#define isvisiblechar(c) (0x21<=(c)&&(c)<=0x7E)
    class MaiScanner {
    public:
        template<typename T> void input_integer(T& var) {
            var = 0;
            T sign = 1;
            int cc = getchar_unlocked();
            for (; cc<'0' || '9'<cc; cc = getchar_unlocked())
                if (cc == '-') sign = -1;
            for (; '0' <= cc&&cc <= '9'; cc = getchar_unlocked())
                var = (var << 3) + (var << 1) + cc - '0';
            var = var*sign;
        }
        inline int c() { return getchar_unlocked(); }
        inline MaiScanner& operator>>(int& var) {
            input_integer<int>(var);
            return *this;
        }
        inline MaiScanner& operator>>(long long& var) {
            input_integer<long long>(var);
            return *this;
        }
        inline MaiScanner& operator>>(string& var) {
            int cc = getchar_unlocked();
            for (; !isvisiblechar(cc); cc = getchar_unlocked());
            for (; isvisiblechar(cc); cc = getchar_unlocked())
                var.push_back(cc);
            return *this;
        }
        template<typename IT> void in(IT begin, IT end) {
            for (auto it = begin; it != end; ++it) *this >> *it;
        }
    };
}
MaiScanner scanner;


class llmod {
public: const ll MOD = MD;
private:
    ll val;
    inline ll cut(ll v) const { return ((v%MOD) + MOD) % MOD; }
public:

    llmod() : MOD(MD), val(0) {}
    llmod(ll num, ll m = MD) : MOD(m), val(cut(num)) {}
    llmod(const llmod& lm, ll m) : MOD(m), val(lm.val) {}

    inline ll operator*() const { return val; }
    inline llmod& operator=(const llmod& lm) { val = lm.val; return *this; }
    inline llmod& operator=(ll v) { val = cut(v); return *this; }

    inline llmod& operator+=(ll v) { val = cut(val + v); return *this; }
    inline llmod& operator+=(const llmod& l) { val = cut(val + l.val); return *this; }
    inline llmod& operator-=(ll v) { val = cut(val - v); return *this; }
    inline llmod& operator-=(const llmod& l) { val = cut(val - l.val); return *this; }
    inline llmod& operator*=(ll v) { val = cut(val * v); return *this; }
    inline llmod& operator*=(const llmod& l) { val = cut(val * l.val); return *this; }
    inline llmod& operator++() { val = (val + 1) % MOD; return *this; }
    inline llmod operator++(int) { llmod t = *this; val = (val + 1) % MOD; return t; }
};
ostream& operator<<(ostream& os, const llmod& l) { os << *l; return os; }

inline llmod operator+(llmod t, const llmod& r) { return t += r; }
inline llmod operator-(llmod t, const llmod& r) { return t -= r; }
inline llmod operator*(llmod t, const llmod& r) { return t *= r; }



// MEMO : 逆元...powm(n,MD-2)
llmod pow(llmod x, ll p) {
    llmod y = 1;
    while (0 < p) {
        if (p % 2)
            y *= x;
        x *= x;
        p /= 2;
    }
    return y;
}

inline llmod& operator/=(llmod& l, const llmod& r) { return l *= pow(r, r.MOD - 2); }


template<typename T>
T powm(T x, T p, T mod = 1000000007ll) {
    T y = 1;
    x = x%mod;
    while (0<p) {
        if (p % 2 == 1) {
            y = (y*x) % mod;
        }
        x = (x*x) % mod;
        p /= 2;
    }
    return y;
}

template<typename T>
T combim(T n, T r, T mod = 1000000007ll) {
    if (n / 2 < r) return combim(n, n - r);
    T p = 1;
    for (; 0<r; r--)
        p = (((p*(n - r + 1)) % mod)*powm(r, mod - 2)) % mod;
    return p;
}


ll m, n, kei;
ll aa, bb, cc, dd;

llmod fact[2020];
llmod factrev[2020];
ll revMD[2020];
// nPr
inline llmod mulseq(ll begin, ll end) {
    // llmod ans = 1;
    // while (begin != end)
    //     ans *= begin,
    //     ++begin;
    // return ans;
    return fact[end - 1] * factrev[begin - 1];
}

llmod dp[2020][1020];
int main() {

    scanner >> n >> aa >> bb >> cc >> dd;

    fact[0] = 1; factrev[0] = 1; revMD[0] = 0;
    iterate(i, 1ll, 1010ll) {
        fact[i] = fact[i - 1] * i;
        factrev[i] = powm(*fact[i], MD-2, MD);
        revMD[i] = powm(i, MD-2, MD);
    }

    dp[0][aa - 1] = 1;

    for (ll assigned = 0; assigned < n; ++assigned) {
        ll left = n - assigned;
        llmod p_a = 1;
        for (ll a = 2; a < aa; ++a)
            p_a *= revMD[a];
        for (ll a = aa; a <= bb && assigned + a*cc <= n; ++a) {
            dp[assigned][a] += dp[assigned][a - 1];
            p_a *= revMD[a];

            llmod p = 1;
            for (ll c = 1; c < cc; ++c)
                p *= p_a,
                p *= mulseq(left - a*c + 1, left - a*c + a + 1),
                p *= revMD[c];
            for (ll c = cc; c <= dd && assigned + a*c <= n; ++c) {
                p *= p_a;
                p *= mulseq(left - a*c + 1, left - a*c + a + 1);
                p *= revMD[c];
                dp[assigned + a*c][a] += dp[assigned][a - 1] * p;
                //cout << a << " " << c << " " <<  p << endl;
            }
        }
    }
    //debugaa(dp, 9, 5)
    llmod ans = 0;
    repeat(g, bb + 1)
        ans += dp[n][g];

    cout << *ans << endl;


    return 0;
}