//#include <cmath>
//#include <ctime>
#include <cstdio>
//#include <cstdlib>
//#include <cstring>

//#include <map>
//#include <set>
//#include <queue>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <iostream>
#include <algorithm>
//#include <functional>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int MAXN = 3005;
const int P = 1000000007;
const int INF = 1000000007;
const double eps = 1e-6;

inline int getint() {
    int r = 0; bool b = true; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') b = false; c = getchar(); }
    while (c >= '0' && c <= '9') { r = (r<<1)+(r<<3) + c - '0'; c = getchar(); }
    return b ? r : -r;
}

int n;
LL a[MAXN], dp[MAXN][MAXN];
bool vis[MAXN][MAXN];

LL dfs(int l, int r) {
    if (l > r) return 0;
    if (l == r) return a[l];
    if (vis[l][r]) return dp[l][r];
    vis[l][r] = true;
    return dp[l][r] = max(a[l] - dfs(l + 1, r), a[r] - dfs(l, r - 1));
}

int main() {
    n = getint();
    for (int i = 1; i <= n; ++i)
        a[i] = getint();
    printf("%lld", dfs(1, n));
}