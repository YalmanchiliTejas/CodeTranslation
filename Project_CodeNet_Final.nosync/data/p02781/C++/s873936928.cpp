#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define ALL(name) name.begin(),name.end()
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
#define MAX_K 5

string N;
int K;

ll dp[MAX_N][MAX_K][2];

ll dfs(int i, int j, int tight) {
    if(i >= N.length()) {
        if(j == K) { return 1; }
        return 0;
    }

    ll& ret = dp[i][j][tight];
    if(~ret) { return ret; }
    ret = 0;

    int r = 9;
    if(tight == 1) { r = N[i] - '0'; }

    for(int num = 0; num <= r; ++num) {
        int next_tight = 0;
        if(tight == 1 && num == r) {
            next_tight = 1;
        }
        if(j == K && num != 0) { continue; }
        ret += dfs(i+1, (num != 0) ? j + 1 : j, next_tight);
    }

    return ret;
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;

    MINUS(dp);
    ll ans = dfs(0, 0, 1);
    printf("%lld\n", ans);

    return 0;
}
