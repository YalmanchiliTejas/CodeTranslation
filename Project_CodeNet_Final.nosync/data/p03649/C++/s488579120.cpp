/*Bismillahir Rahmanir Rahim*///{
#include <bits/stdc++.h>
using namespace std;
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
template<class C, size_t X> typename enable_if<sizeof(C)!=1, Dbg&>::type operator <<(C (&x)[X]) {
    return dump(begin(x), end(x));
}
template<class B, class C> Dbg &operator <<(const pair<B, C> &x) {
    return *this << '{' << x.first << ", " << x.second << '}';
}
template<class C, size_t Y> struct TP {
    void operator()(Dbg& os, const C &t) { TP<C, Y-1>()(os, t); os << ", " << get<Y-1>(t); }
};
template<class C> struct TP<C, 1> { void operator()(Dbg& os, const C &t) { os << get<0>(t); } };
template<class... C> Dbg& operator<<(const tuple<C...> &t) {
    os << '{', TP<decltype(t), sizeof...(C)>()(*this, t); return *this << '}';
}
Dbg &operator<<(ostream&(*x)(std::ostream&)) { os << x; return *this; }
} dbg;
void err(istringstream *iss) { delete iss; }
template<class C, class... Args> void err(istringstream *iss, const C &val, const Args &... args) {
    string name; *iss >> name; if (name.back()==',') name.pop_back();
    dbg << name << " = " << val << "; ", err(iss, args ...);
}
#define bug(args...) dbg << __LINE__ << ": ", err(new istringstream(string(#args)), args), dbg << endl
#define sl(a) int(strlen(a))
#define sz(a) int(a.size())
int T, Q, cn;//}
const int inf = 1000000007, mxn = 55;

int n;
ll a[mxn];

ll Ceil(ll x, int y) { return x ? ((x-1)/y+1) : 0ll; }

bool check(ll x) {
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += Ceil(max(a[i]+x-(n-1), 0ll), n+1);
        if (tot>x) return 0;
    }
    return 1;
}

signed main() { ios::sync_with_stdio(0); cin.tie(NULL); cout.precision(11);
/*
Increase everyone except max by 1 + decrease max by n, can be converted to: increase everyone by 1, decrease max by n+1.
As number of moves can be huge, we can try to fix number of moves x, but it isn't monotonic or unimodal.
For x moves, we increase everyone by x, decrease by n+1 at most x times. Making max < n means each element < n.
 ==> After n+1 moves, we must do at least 1 decrement per element (as now everyone is surely >= n for being increased by
n+1), which will bring it back to initial, but we still have one decrement by n+1 operation left. ==> We can express total
number of moves x as y*(n+1)+z, where z is less than n+1. ==> We can easily find max value of y by finding sum of enough
number of decrements (ceil) for each element, min value of y by finding must needed (again ceil, but at most n can be supplied
by z) decrements.
*/
    cin >> n;
    ll minNeeded = 0, maxNeeded = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxNeeded += Ceil(max(a[i]-(n-1), 0ll), n+1), minNeeded += max(0ll, Ceil(max(a[i]-(n-1), 0ll), n+1)-n);
    }
    for (ll i = minNeeded*(n+1); i <= maxNeeded*(n+1); i++) {
        if (check(i)) return cout << i << '\n', 0;
    }
}