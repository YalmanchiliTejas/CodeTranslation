//#undef DEBUG
#include <bits/stdc++.h>
#include <ext/numeric>
using namespace std; using __gnu_cxx::power;
using ll = long long; using ull = unsigned long long; using ld = long double;
const ll llinf = (1ll<<61)-1; const double eps = 1e-6, ldeps = 1e-9;
const char lf = '\n', splf[] = " \n";
#define all(x) begin(x), end(x)
#define sl(a) int(strlen(a))
#define sz(a) int(a.size())
#define TCC template<class C
struct Dbg { static constexpr auto &os = cout;   // replace by cerr in interactive.
#define ENI typename enable_if<
#define DTOR , Dbg&>::type operator<<
#define RIS return *this
TCC> static auto o(C *x)->decltype(os << *x, 0);
TCC> static char o(...);
TCC> ENI sizeof o<C>(0)!=1 DTOR(const C &x) {os<<x; RIS;}
TCC> Dbg &dump(C b, C e) {
    int ii = 0;
    for(C i = (os << "\n[", b); i!=e and ii<26; i++, ii++) *this << ", "+2*(i==b) << *i;
    RIS << ']';
}
TCC> ENI sizeof o<C>(0)==1 DTOR(const C &x) {
    return dump(all(x));
}
TCC, size_t X> ENI !is_same<C, const char>::value DTOR(C (&x)[X]) {
    return dump(all(x));
}
TCC, class D> Dbg &operator<<(const pair<C, D> &x) {RIS<<'{'<<x.first<<", "<<x.second<<'}';}
Dbg &operator<<(ostream&(*x)(ostream&)) { os << x; RIS; }
} dbg;
void err(istringstream *iss) { delete iss; }
TCC, class... Args> void err(istringstream *iss, const C &val, const Args &... args) {
    string name; *iss >> name; if (name.back()==',') name.pop_back();
    dbg << name << " = " << val << "; ", err(iss, args...);
}
#ifdef DEBUG
#define bug(args...) dbg << __LINE__ << ": ", err(new istringstream(#args), args), dbg << endl
#define cbug(a, args...) if (a) bug(args);
#else
#define bug(args...) void()
#define cbug(a, args...)
#endif
#define ASSERT(a, o, b, args...) if (!((a)o(b))) bug(a, b, ##args), assert((a)o(b));
int T = 1, Q, cn;
const int inf = 1000000007, mxn = -1;

template<class C, class D> bool operator ==(const C &ls, const D &rs) { return !(ls<rs or rs<ls); }
template<class C, class D> bool operator !=(const C &ls, const D &rs) { return !(rs==ls); }
template<class C, class D> bool operator >(const C &ls, const D &rs) { return (rs<ls); }
template<class C, class D> bool operator <=(const C &ls, const D &rs) { return !(rs<ls); }
template<class C, class D> bool operator >=(const C &ls, const D &rs) { return !(ls<rs); }
template<class C, class D> C& operator +=(C &x, const D &y) { return x = x+y; }//{
template<class C, class D> C& operator -=(C &x, const D &y) { return x = x-y; }
template<class C, class D> C& operator *=(C &x, const D &y) { return x = x*y; }

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

Int operator""_i(unsigned long long x) { return {int(x)}; }//}

signed main() { cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit); cout.precision(11), cout.setf(ios::fixed);
    //cin >> T;
    auto kase = [&]()->void {   // if T>1, inputAll + resetAll -> solution
        //cout << "Case " << cn << ":";
        int n;
        Int ans=0,ps=0;
        cin>>n;
        for(int i=0,x;i<n;++i){
            cin>>x;
            ans+=ps*x,ps+=x;
        }
        cout<<ans<<lf;
    };
    while (cn++!=T) kase();
}
