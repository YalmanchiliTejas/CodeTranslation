#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <random>
#include <set>
#include <sstream>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
typedef long double LD;
using namespace std;
const int INF = 2147483647;
const int INF2 = 0x3f3f3f3f;
const ll INF64 = 1e18;
const double INFD = 1e30;
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 998244353;
template <typename T>
inline T read() {
    T X = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch)) {
        w |= ch == '-';
        ch = getchar();
    }
    while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
    return w ? -X : X;
}
const int MAXN = 3005;
int n, m, k;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int dr2[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dc2[8] = {1, 0, -1, 1, 0, -1, 1, -1};
int CASE = 1;
int arr[MAXN];
ll dp[MAXN][MAXN];
ll sum[MAXN];
int main() {
#ifdef LOCALLL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][arr[i]] += i;
        for (int k = 0; k <= m; k++) {
            if (k < arr[i])
                dp[i][k] = (dp[i][k] + dp[i - 1][k]) % MOD;
            else
                dp[i][k] =
                    (dp[i][k] + dp[i - 1][k] + dp[i - 1][k - arr[i]]) % MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += dp[i][m];
        if (ans >= MOD) ans -= MOD;
    }
    printf("%lld", ans);
    return 0;
}