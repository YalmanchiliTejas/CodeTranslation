/*Bismillahir Rahmanir Rahim*///{
#include <bits/stdc++.h>
#include <ext/numeric>
using namespace std; using __gnu_cxx::power;
using ll = long long; using ull = unsigned long long; using ld = long double;
const ll llinf = (1ll<<61)-1;
const double eps = 1e-6, ldeps = 1e-9;
struct Dbg {
static constexpr auto &os = cout;   // replace by cerr in interactive.
template<class C> static auto dud(C *x)->decltype(os << *x, 0);
template<class C> static char dud(...);
template<class C> typename enable_if<sizeof dud<C>(0)!=1, Dbg&>::type operator<<(const C &x) { os << x; return *this; }
template<class C> Dbg &dump(C b, C e) {
    *this << "\n[";
    int cur = 0;
    for (C i = b; i!=e and cur<26; i++, cur++) *this << ", "+2*(i==b) << *i;
    return *this << ']';
}
template<class C> typename enable_if<sizeof dud<C>(0)==1, Dbg&>::type operator<<(const C &x) {
    return dump(begin(x), end(x));
}
template<class C, size_t X> typename enable_if<!is_same<C, const char>::value, Dbg&>::type operator <<(C (&x)[X]) {
    return dump(begin(x), end(x));
}
template<class B, class C> Dbg &operator <<(const pair<B, C> &x) {
    return *this << '{' << x.first << ", " << x.second << '}';
}
Dbg &operator<<(ostream&(*x)(std::ostream&)) { os << x; return *this; }
} dbg;
void err(istringstream *iss) { delete iss; }
template<class C, class... Args> void err(istringstream *iss, const C &val, const Args &... args) {
    string name; *iss >> name; if (name.back()==',') name.pop_back();
    dbg << name << " = " << val << "; ", err(iss, args...);
}
#define bug(args...) dbg << __LINE__ << ": ", err(new istringstream(#args), args), dbg << endl
#define cbug(a, args...) if (a) bug(args);
#define ASSERT(a, o, b, args...) if (!((a)o(b))) bug(a, b, ##args), assert((a)o(b));
#define sl(a) int(strlen(a))
#define sz(a) int(a.size())
int T, Q, cn;//}
const int inf = 1000000007, mxn = 1005;

template<class C, class D> C& operator +=(C &x, const D &y) { return x = x+y; }//{
template<class C, class D> C& operator -=(C &x, const D &y) { return x = x-y; }
template<class C, class D> C& operator *=(C &x, const D &y) { return x = x*y; }
template<class C, class D> bool operator ==(const C &ls, const D &rs) { return !(ls<rs or rs<ls); }
template<class C, class D> bool operator !=(const C &ls, const D &rs) { return !(rs==ls); }
template<class C, class D> bool operator >(const C &ls, const D &rs) { return (rs<ls); }
template<class C, class D> bool operator <=(const C &ls, const D &rs) { return !(rs<ls); }
template<class C, class D> bool operator >=(const C &ls, const D &rs) { return !(ls<rs); }

struct Int// Make sure to not do any operation with non-modded(except *, which must be int, *1 to mod forcefully)
{
    int x;
    Int() = default;
    Int(const int &rs) : x(rs + (rs>=0 ? 0 : inf)) {};
    Int operator -() { return inf-*this; }
    // Int operator ~() = delete;
    Int operator ~() { return power(*this, inf-2); }
    Int operator +(const Int &rs) const { return x+rs.x>=inf ? x+rs.x-inf : x+rs.x; }
    Int operator -(const Int &rs) const { return x-rs.x<0 ? x-rs.x+inf : x-rs.x; }
    Int operator *(const Int &rs) const { return int(x*ll(rs.x)%inf); }
    Int operator <<(const int &rs) { return rs==1 ? *this+*this : *this*Int{1<<rs}; }
    Int& operator <<=(const int &rs) { return *this = *this<<rs; }
    Int& operator >>=(const int &rs) { return x>>=rs, *this; }  // only for power()
    Int& operator ++() { return *this += 1; }
    Int& operator --() { return *this -= 1; }
    Int operator ++(int) { Int ret = x; ++*this; return ret; }
    Int operator --(int) { Int ret = x; --*this; return ret; }
    friend istream& operator >>(istream &is, Int &rs) { return is>>rs.x; }
    friend ostream& operator <<(ostream &os, const Int &rs) { return os<<rs.x; }
    friend Int operator +(const Int &ls, const int &rs) { return ls+Int(rs); }
    friend Int operator +(const int &ls, const Int &rs) { return Int(ls)+rs; }
    friend Int operator -(const Int &ls, const int &rs) { return ls-Int(rs); }
    friend Int operator -(const int &ls, const Int &rs) { return Int(ls)-rs; }
    friend Int operator *(const Int &ls, const int &rs) { return ls*Int(rs); }
    friend Int operator *(const int &ls, const Int &rs) { return Int(ls)*rs; }
    bool operator <(const Int &rs) const { return x<rs.x; }
    friend bool operator <(const int &ls, const Int &rs) { return ls<rs.x; }
    friend bool operator <(const Int &ls, const int &rs) { return ls.x<rs; }
};

Int operator""_i(unsigned long long x) { return {int(x)}; }

Int facMod[mxn], invfacMod[mxn], invMod[mxn];

void preFacModInvMod(int _n) {
    facMod[0] = facMod[1] = invfacMod[0] = invfacMod[1] = invMod[0] = invMod[1] = 1;
    for (int i = 2; i<=_n; i++) invMod[i] = -invMod[inf%i]*(inf/i);
    for (int i = 2; i<=_n; i++) facMod[i] = facMod[i-1]*i, invfacMod[i] = invfacMod[i-1]*invMod[i];
}

Int ncr(int _n, int r) { return (_n<0 || r<0 || r>_n) ? 0_i : facMod[_n]*invfacMod[r]*invfacMod[_n-r]; }//}

int n, a, b, c, d;
Int dp[mxn][mxn];

signed main() { cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit); cout.precision(11);
    cin >> n >> a >> b >> c >> d;
    preFacModInvMod(n);
    dp[a-1][0] = 1;
    for (int i = a; i <= b; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i-1][j];
        }
        Int os = 1;
        for (int j = 1, o = i*j; j<c and o<=n; j++, o+=i) {
            os *= ncr(o-1, i-1);
        }
        for (int j = c, o = i*j; j<=d and o<=n; j++, o+=i) {
            os *= ncr(o-1, i-1);
            for (int k = o; k <= n; k++) {
                dp[i][k] += dp[i-1][k-o]*ncr(k, o)*os;
            }
        }
    }

    cout << dp[b][n] << '\n';
}