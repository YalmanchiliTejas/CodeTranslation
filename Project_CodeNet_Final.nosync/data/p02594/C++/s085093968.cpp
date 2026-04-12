#include <bits/stdc++.h>
using namespace std;
#define CPP_CAT(x,y) CPP_CAT_I(x,y)
#define CPP_CAT_I(x,y) x ## y

using i8  = int8_t;
using u8  = uint8_t;
using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f32 = float;
using f64 = double;
using ll = long long;
constexpr i64 INF = 1010000000000000017LL;
constexpr i64 MOD = 1000000007LL;
constexpr f64 EPS = 1e-12;
constexpr f64 PI = 3.14159265358979323846;
#define FOR(i, start, end) for(i64 i = (start), CPP_CAT(i,xxxx_end)=(end); i < CPP_CAT(i,xxxx_end); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
template<typename T, typename U, typename Comp=less<>>
bool chmax(T& xmax, const U& x, Comp comp={}) {
    if(comp(xmax, x)) {
        xmax = x; 
        return true;
    }
    return false;
}
template<typename T, typename U, typename Comp=less<>>
bool chmin(T& xmin, const U& x, Comp comp={}) {
    if(comp(x, xmin)) {
        xmin = x; 
        return true;
    }
    return false;
}
template<typename Val>
bool bitcheck(Val bit, size_t idx) {
    return bit & (1 << idx);
}
struct ProconInit {
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = false;
    ProconInit() {
        cin.tie(nullptr); ios::sync_with_stdio(false);
        cout << fixed << setprecision(IOS_PREC);
        if(AUTOFLUSH) cout << unitbuf;
    }
} PROCON_INIT;

void solve() {
    int x; cin >> x;
    if (x >= 30) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main() {
    solve();
    return 0;
}