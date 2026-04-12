#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

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
const int MOD = 1000000007;
#define MAX_N 10

int N, M;
vector<int> graph[MAX_N];
int comp = 0;

// 今 i 番目の頂点にいて、 visited の頂点に訪れているときの
// パターン数
int dfs(int i = 0, int visited = 0) {
    visited |= (1 << i);
    if((visited & comp) == comp) { return 1; }
    int res = 0;
    for(auto& v : graph[i]) {
        if(((visited >> v) & 1) == 0) { res += dfs(v, visited); }
    }
    return res;
}

signed main()
{
    cin >> N >> M;
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    comp = ((1 << N) - 1);
    printf("%lld\n", dfs());
    return 0;
}
