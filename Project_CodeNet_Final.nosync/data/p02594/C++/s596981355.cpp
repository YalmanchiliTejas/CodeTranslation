#define DEBUG
#include <bits/stdc++.h>
#include <ext/numeric>
using namespace std; using __gnu_cxx::power;
using ll = long long; using ull = unsigned long long; using ld = long double;
const ll llinf = (1ll<<61)-1; const double eps = 1e-6, ldeps = 1e-9;
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
#else
#define bug(args...) 0
#endif
#define ASSERT(a, o, b, args...) if (!((a)o(b))) bug(a, b, ##args), assert((a)o(b));
int T = 1, Q, cn;
const int inf = 1000000007, mxn = -1;

signed main() { cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit); cout.precision(11), cout.setf(ios::fixed);
    // cin >> T;
    auto inputAll = [&]()->void {
        
    };
    auto kase = [&]()->void {
        // cout << "Case " << cn << ": ";
        int x;
        cin>>x;
        cout<<(x>=30 ? "Yes":"No")<<'\n';
    };
    auto resetAll = [&]()->void {
        
    };
    while (cn++!=T) inputAll(), kase(), resetAll();
}
