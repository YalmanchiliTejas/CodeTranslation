#include <bits/stdc++.h>
#define For(i, a, b) for (int(i) = (int)(a); (i) < (int)(b); ++(i))
#define rFor(i, a, b) for (int(i) = (int)(a)-1; (i) >= (int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T div_floor(T a, T b) {
    if (b < 0) a *= -1, b *= -1;
    return a >= 0 ? a / b : (a + 1) / b - 1;
}
template <class T>
T div_ceil(T a, T b) {
    if (b < 0) a *= -1, b *= -1;
    return a > 0 ? (a - 1) / b + 1 : a / b;
}

constexpr lint mod = 1000000007;
constexpr lint INF = mod * mod;
constexpr int MAX = 200010;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    bool G[n][n];
    rep(i, n) rep(j, n) G[i][j] = false;
    rep(i, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        G[a][b] = G[b][a] = true;
    }
    int p[n];
    iota(p, p + n, 0);
    int ans = 0;
    do {
        bool flag = true;
        rep(i, n - 1) if (!G[p[i]][p[i + 1]]) {
            flag = false;
            break;
        }
        ans += flag;
    } while (next_permutation(p + 1, p + n));
    printf("%d\n", ans);
}