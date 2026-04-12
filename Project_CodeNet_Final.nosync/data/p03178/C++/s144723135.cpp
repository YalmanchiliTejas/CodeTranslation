#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#if __cplusplus >= 201103L
#include <chrono>
using namespace std::chrono;
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#ifdef LOCAL
#define prl puts("\n------------------\n")
#define prln(x) (cout << #x << ' ' << x << endl)
#define pr(x) (cout << #x << ' ' << x << ' ' )
#define prv(x) (cout << x << ' ')
#else
#define prl 
#define prln(x) 
#define pr(x)
#define prv(x)
#endif
#define clr(x) memset((x), 0, sizeof((x)))
#define clr1(x) memset((x), -1, sizeof((x)))
#define endl "\n"
#define pi acos(-1)
#define rep(i, st, ed) for (int i = (st); i <= (ed); ++i)
#define rep0(i, st, ed) for (int i = (st); i < (ed); ++i)
#define per(i, st, ed) for (int i = (st); i >= ed; --i)
template<class T> void _sf(T &x) {cin >> x;}
void _sf(int &x) {scanf("%d", &x);}
void _sf(ll &x) {scanf("%lld", &x);}
void _sf(double &x) {scanf("%lf", &x);}
void _sf(char &x) {scanf(" %c", &x);}
void _sf(char *x) {scanf("%s", x);}
void sf() {}
template <class T, class...U> void sf(T & head, U&... tail) { _sf(head); sf(tail...);}
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
const int maxn = 1e4 + 5;
ll dp[maxn][105];
int a[maxn], len, d;
char str[maxn];

ll dfs(int pos, int now, bool limit) {
    if (pos == len + 1) {
        return dp[pos][now] = (now == 0);
    }
    if (!limit && dp[pos][now] != -1) {
        return dp[pos][now];
    }
    int up = limit ? a[pos] : 9;
    ll sum  = 0;
    for (int i = 0;i <= up; ++i) {
        sum += dfs(pos + 1, (now + i) % d, limit && i == up);
        if (sum >= mod) sum -= mod;
    }
    if (!limit) dp[pos][now] = sum;
    return sum;
}


int main(){
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        #if __cplusplus >= 201103L
        auto start = steady_clock::now();
        #endif
    #endif
    cin >> str + 1;
    cin >> d;
    len = strlen(str + 1);
    rep(i, 1, len) a[i] = str[i] - '0';
    memset(dp, -1, sizeof(dp));
    ll ans = dfs(1, 0, true) - 1;
    cout << (ans + mod) % mod << endl;

    #ifdef LOCAL
        #if __cplusplus >= 201103L
        auto end = steady_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(end - start);;
        printf("Total time: %.6fs\n", time_span.count());
        #endif
    #endif
    return 0;
}