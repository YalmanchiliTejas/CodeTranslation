#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double LD;
using namespace std;
const int INF = 2147483647;
const int INF2 = 0x3f3f3f3f;
const ll INF64 = 3e18;
const double INFD = 1e30;
const double EPS = 1e-10;
const long double PI = acosl(-1);
const int MOD = 1e9 + 7;
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
const int MAXN = 2505;
const int MAXV = 60;
int n, m, k;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int dr2[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dc2[8] = {1, 0, -1, 1, 0, -1, 1, -1};
int CASE = 1;

struct FenwickTree {
    FenwickTree() {}
    inline void increase(int r, int c, int x) {
        for (int i = r; i <= n; i += lowbit(i))
            for (int j = c; j <= m; j += lowbit(j)) {
                a[i][j] += x;
                b[i][j] += r * x;
                d[i][j] += c * x;
                e[i][j] += r * c * x;
            }
    }
    inline int getSum(int r, int c) {
        int ans = 0;
        for (int i = r; i; i -= lowbit(i))
            for (int j = c; j; j -= lowbit(j)) {
                ans += a[i][j] * (r + 1) * (c + 1);
                ans -= b[i][j] * (c + 1);
                ans -= d[i][j] * (r + 1);
                ans += e[i][j];
            }
        return ans;
    }
    int a[MAXN][MAXN], b[MAXN][MAXN], d[MAXN][MAXN], e[MAXN][MAXN];
    inline int lowbit(int x) { return x & (-x); }
};

int main() {
#ifdef LOCALLL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    scanf("%d", &n);
    printf("%s\n", n >= 30 ? "Yes" : "No");
    return 0;
}