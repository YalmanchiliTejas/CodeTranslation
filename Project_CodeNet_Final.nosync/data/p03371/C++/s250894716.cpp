#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

template<typename T1,typename T2> inline void chmin(T1 &a, T2 b){ if(a > b) a = b; }
template<typename T1,typename T2> inline void chmax(T1 &a, T2 b){ if(a < b) a = b; }

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
const int MAX_N = 100010;

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = LLINF;
    // A で A, B で B
    int cand = A * X + B * Y;
    chmin(ans, cand);

    // AB で A, 残りを B
    cand = C * X * 2;
    if(X < Y) {
        cand += (Y - X) * B;
    }
    chmin(ans, cand);

    // AB で B, 残りを A
    cand = C * Y * 2;
    if(Y < X) {
        cand += (X - Y) * A;
    }
    chmin(ans, cand);

    // 全部 AB
    cand = max(X, Y) * C * 2;
    chmin(ans, cand);

    printf("%lld\n", ans);

    return 0;
}