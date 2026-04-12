// #pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define String std::string
#define fi first
#define se second
#define mp std::make_pair
#define Pair std::pair<int, int>
#define Map std::map< int, int >
#define Vector std::vector<int>
#define LEAD (lead && !i)
#define LIM (lim && i == buc[pos])
#define ABS(x) (x) < 0 ? (-x) : (x)
#define RG register
 
using std::cin;
using std::cout;
using std::endl;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int N = 300000 + 5;
const int M = 1000 + 5;
const int K = 1e7 + 5;
const int MOD = 1e9 + 7;
const int inv2 = 500000004;
const int LOG = 40;
const ull BASE = 19260817;
const int INF = 0x3f3f3f3f;
const int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };
const int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };
// const double PI = acos(-1);
const double PI = 3.14159;

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
template<class T>
inline T readT() {
    T res = 0, f = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) res = (res << 1) + (res << 3) + ch - '0';
    return res * f;
}
#define read readT<int>

namespace Comb{
const int N = 10 + 5;
inline void exgcd(ll a, ll b, ll &g, ll &x, ll &y) {
    if (!b) g = a, x = 1, y = 0;
    else exgcd(b, a % b, g, y, x), y -= x * (a / b);
}
 
inline ll inv(ll a) {
    ll g, res, tmp;
    exgcd(a, MOD, g, res, tmp);
    return ((res % MOD) + MOD) % MOD;
}
 
ll f[N], invFact[N];
 
inline void prepare() {
    f[0] = 1;
    int n = 200000;
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % MOD;
    invFact[n] = inv(f[n]);
    for (int i = n - 1; i >= 1; i--) invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}
 
inline ll C(int n, int m) {
    if (!m) return 1;
    if (n == m) return 1;
    if (m > n) return 0;
    if (m < 0) return 0;
    return f[n] * invFact[m] % MOD * invFact[n - m] % MOD;
}
}

int n, m;
char map[55][55];
bool vis[55][55];

inline bool check(int x, int y) {
    if (x < 1 || x > n) return false;
    if (y < 1 || y > m) return false;
    return !vis[x][y] && map[x][y] == '#';
}

inline void bfs() {
    std::queue< Pair > q;
    q.push(mp(1, 1));
    vis[1][1] = true;
    while (!q.empty()) {
        int x = q.front().fi, y = q.front().se;
        q.pop();
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny)) {
                vis[nx][ny] = true;
                q.push(mp(nx, ny));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%s", map[i] + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (map[i][j] == '#') cnt++;
    puts(cnt == n + m - 1 ? "Possible" : "Impossible");
    return 0;
}