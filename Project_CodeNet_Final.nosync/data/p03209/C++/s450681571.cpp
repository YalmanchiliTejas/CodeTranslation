#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
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
#define MAX_N 60

// レベル i の時の全体の長さ
ll length[MAX_N];

// n, x の時の P の数を返す
ll dfs(ll n, ll x) {
    if(x == 0) { return 0; }
    if(n == 1) { return (x == 5) ? 3 : x - 1; }
    // x を 2 つに分ける
    if(x - 1 <= length[n-1]) { return dfs(n-1, x-1); }
    if(x == length[n]) { return 1 + dfs(n-1, length[n-1]) * 2; }
    ll x1 = length[n-1];
    ll x2 = x - length[n-1] - 2;
    return 1 + dfs(n-1, x1) + dfs(n-1, x2);
}

signed main()
{
    ll N, X;
    cin >> N >> X;

    // length の作成
    length[0] = 1;
    for(int i = 1; i < MAX_N; ++i) { length[i] = 3 + length[i-1] * 2; }

    ll ans = dfs(N, X);
    printf("%lld\n", ans);
    return 0;
}
