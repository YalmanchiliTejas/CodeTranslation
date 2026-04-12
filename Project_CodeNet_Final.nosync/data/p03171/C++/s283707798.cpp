#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int MAXN = 3456;
const LL INF = (LL)1e15;
int a[MAXN];
bool visit[MAXN][MAXN][2];
LL dp[MAXN][MAXN][2];

LL dfs(int x, int y, int flg) {
   if (visit[x][y][flg]) return dp[x][y][flg];
   visit[x][y][flg] = 1;
   if (y < x) return 0;
   LL ans;
   if (flg == 0) {
      ans = max(dfs(x + 1, y, 1) + a[x], dfs(x, y - 1, 1) + a[y]);
   } else {
      ans = min(dfs(x + 1, y, 0) - a[x], dfs(x, y - 1, 0) - a[y]);
   }
   return dp[x][y][flg] = ans;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    printf("%lld\n", dfs(0, N - 1, 0));
    return 0;
}
