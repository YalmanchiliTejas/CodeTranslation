#include <bits/stdc++.h>

using std::pair;
using std::vector;
using std::string;

typedef long long ll;
typedef pair<int, int> pii;

#define fst first
#define snd second
#define pb(a) push_back(a)
#define mp(a, b) std::make_pair(a, b)
#define debug(...) fprintf(stderr, __VA_ARGS__)

template <typename T> bool chkmax(T& a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> bool chkmin(T& a, T b) { return a > b ? a = b, 1 : 0; }

const int oo = 0x3f3f3f3f;

string procStatus() {
    std::ifstream t("/proc/self/status");
    return string(std::istreambuf_iterator<char>(t), std::istreambuf_iterator<char>());
}

template <typename T> T read(T& x) {
    int f = 1; x = 0;
    char ch = getchar();
    for(;!isdigit(ch); ch = getchar()) if(ch == '-') f = -1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    return x *= f;
}

const int N = 100;
const int mo = 1e9 + 7;

inline int fpm(int x, int y) {
    int res = 1;
    for(; y > 0; y >>= 1) {
        if(y & 1)
            res = (ll) res * x % mo;
        x = (ll) x * x % mo;
    }
    return res;
}

int n;
int a[N + 5], cnt;
int dp[N + 5][2];

inline void add(int &x, int y) {
    (x += y) >= mo ? x -= mo : 0;
}

pii solve(int l, int r, int base = 0) {
    if(l == r) {
        return mp(fpm(2, a[l] - base), 0);
    }

    int mn = oo;
    int u = ++ cnt;

    dp[u][0] = 1;
    for(int i = l; i <= r; ++i) { chkmin(mn, a[i]); }
    for(int i = l; i <= r; ++i) {
        if(a[i] > mn) {
            int j = i;
            while(j + 1 <= r && a[j + 1] > mn) { ++ j; }
            pii temp = solve(i, j, mn);

            if(i != l) {
                dp[u][1] = ((ll) dp[u][1] * (temp.snd + 2ll * temp.fst) % mo + 
                           (ll) dp[u][0] * (temp.snd + temp.fst) % mo) % mo;
                dp[u][0] = (ll) dp[u][0] * temp.fst % mo;
            } else {
                dp[u][1] = temp.snd;
                dp[u][0] = (ll) dp[u][0] * (2ll * temp.fst) % mo;
            }

            i = j;
        } else {
            if(i != l) {
                dp[u][1] = ((ll) dp[u][1] * 2 + dp[u][0]) % mo;
            } else {
                dp[u][0] = 2;
            }
        }
    }

    return mp((ll) dp[u][0] * fpm(2, mn - base - 1) % mo, dp[u][1]);
}

int main() {
#ifdef Wearry
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    read(n);
    for(int i = 1; i <= n; ++i) read(a[i]);

    pii ans = solve(1, n);
    printf("%d\n", (ans.fst + ans.snd) % mo);

    return 0;
}
