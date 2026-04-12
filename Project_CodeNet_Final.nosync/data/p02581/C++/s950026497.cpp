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
#include <unordered_map>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int MAXN = 2345;
const int INF = 6789;
struct node {
    int a, b, x;
    node(int _a, int _b, int _x) {
        a = _a;
        b = _b;
        x = _x;
    }
};

int dp[MAXN][MAXN];
vector<node> tmp_dp;
int max_dp[MAXN];
int A[3 * MAXN];

void update(int a, int b, int c, int N, int bst) {
    //take 2
    tmp_dp.push_back(node(a, b, dp[c][c] + 1));
    tmp_dp.push_back(node(a, b, bst));
    //take 1
    for (int i = 1; i <= N; i++) {
        if (b == c)
            tmp_dp.push_back(node(i, a, dp[b][i] + 1));
        // replace x in (i, x) with a, x is random variable
        tmp_dp.push_back(node(i, a, max_dp[i]));
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < 3 * N; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= N; i++) {
        max_dp[i] = -INF;
        for (int j = 1; j <= N; j++)
            dp[i][j] = -INF;
    }
    dp[A[1]][A[0]] = dp[A[0]][A[1]] = 0;
    max_dp[A[1]] = max_dp[A[0]] = 0;
    int ans = 0, offs = 0, bst = 0;
    for (int i = 0; i < N - 1; i++) {
        int a = A[3 * i + 2], b = A[3 * i + 3], c = A[3 * i + 4];
        if (a == b && b == c) {
            offs++;
            continue;
        }
        tmp_dp.clear();
        assert(tmp_dp.empty());
        update(a, b, c, N, bst);
        update(b, c, a, N, bst);
        update(c, a, b, N, bst);
        for (auto i : tmp_dp) {
            int x = i.a, y = i.b, z = i.x;
            dp[x][y] = dp[y][x] = max(dp[x][y], z);
            max_dp[x] = max(max_dp[x], z);
            max_dp[y] = max(max_dp[y], z);
            bst = max(bst, z);
        }
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            ans = max(ans, dp[i][j]);
    printf("%d\n", max(ans, dp[A[3 * N - 1]][A[3 * N - 1]] + 1) + offs);
    return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
by Benq;
*/
