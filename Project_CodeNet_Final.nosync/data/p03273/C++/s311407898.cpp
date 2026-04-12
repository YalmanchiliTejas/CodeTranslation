#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(ll i=0;i<n;++i)
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
#define MAX_N 110

int H, W;
string A[MAX_N];
bool noH[MAX_N] = {};
bool noW[MAX_N] = {};

static inline bool isWhite(int y) {
    REP(i, W) { if(A[y][i] == '#') { return false; } }
    return true;
}

static inline bool isWhite2(int x) {
    REP(i, H) { if(A[i][x] == '#') { return false; } }
    return true;
}

signed main()
{
    cin >> H >> W;
    REP(i, H) {
        cin >> A[i];
    }

    REP(i, H) { if(isWhite(i)) { noH[i] = true; } }
    REP(i, W) { if(isWhite2(i)) { noW[i] = true; } }

    REP(i, H) {
        if(noH[i]) { continue; }
        REP(j, W) {
            if(noW[j]) { continue; }
            printf("%c", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
