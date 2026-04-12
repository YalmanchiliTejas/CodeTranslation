#include <bits/stdc++.h>
using namespace std;

#define CPP_STR(x) CPP_STR_I(x)
#define CPP_CAT(x,y) CPP_CAT_I(x,y)
#define CPP_STR_I(args...) #args
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

#define FOR(i, start, end) for(i64 i = (start), CPP_CAT(i,xxxx_end)=(end); i < CPP_CAT(i,xxxx_end); ++i)
#define REP(i, n) FOR(i, 0, n)
#define REPS(i, n) for(i64 i = 1; i <= n; ++i)
#define RREP(i, n) for(i64 i = n - 1; i >= 0 ; --i)
#define RREPS(i, n) for(i64 i = n; i >= 1; --i)

#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))

#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define pb push_back
#define mp make_pair
#define F first
#define S second

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template<typename C>
i64 SIZE(const C& c) { return static_cast<i64>(c.size()); }

template<typename T, size_t N>
i64 SIZE(const T (&)[N]) { return static_cast<i64>(N); }


struct ProconInit {
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = false;

    ProconInit() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(IOS_PREC);
        if(AUTOFLUSH)
            cout << unitbuf;
    }
} PROCON_INIT;


#define MAX_N 50
i64 n_layer[MAX_N + 1];
i64 n_patty[MAX_N + 1];

i64 rec(i64 i, i64 x) {
    if (i == 0) {
        if (x > 0) return 1;
        else return 0;
    }

    if (x >= n_layer[i]) return n_patty[i];

    if (x <= 1) return 0;
    else if (x <= 1 + n_layer[i - 1]) return rec(i - 1, x - 1);
    else if (x <= 1 + n_layer[i - 1] + 1) return n_patty[i - 1] + 1;
    else if (x <= 1 + 2 * n_layer[i - 1] + 1) return n_patty[i - 1] + 1 + rec(i - 1, x - (1 + n_layer[i - 1] + 1));
    else return 2 * n_patty[i - 1];
}

int main() {
    i64 N, X; cin >> N >> X;

    n_layer[0] = 1;
    n_patty[0] = 1;
    REP(i, N) {
        n_layer[i + 1] = 2 * n_layer[i] + 3;
        n_patty[i + 1] = 2 * n_patty[i] + 1;
    }

    i64 n = rec(N, X);
    cout << n << endl;

    return 0;
}