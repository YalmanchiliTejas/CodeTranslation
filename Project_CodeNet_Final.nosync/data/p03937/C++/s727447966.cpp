#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(ll i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 0
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
#define MAX_N 10

int H, W;
string graph[MAX_N];

bool dfs(int i = 0, int j = 0) {
    if(i == H-1 && j == W-1) { return true; }
    if(i < H-1 && graph[i+1][j] == '#') {
        bool ret = dfs(i+1, j);
        if(ret) { return true; }
    }
    if(j < W-1 && graph[i][j+1] == '#') {
        bool ret = dfs(i, j+1);
        if(ret) { return true; }
    }
    return false;
}

signed main()
{
    cin >> H >> W;
    REP(i, H) {
        cin >> graph[i];
    }
    int cnt = 0;
    REP(i, H) {
        REP(j, W) {
            if(graph[i][j] == '#') { cnt++; }
        }
    }
    if(cnt != H + W - 1) {
        printf("Impossible\n");
        return 0;
    }
    if(dfs()) { printf("Possible\n"); }
    else { printf("Impossible\n"); }

    return 0;
}
