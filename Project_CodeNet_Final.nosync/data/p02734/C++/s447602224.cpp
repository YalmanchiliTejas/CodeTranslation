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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;
using namespace __gnu_pbds;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set;
const int MAXN = 3456;
const int MOD = 998244353;
int A[MAXN];
int dp[MAXN];
int ndp[MAXN];

int add(int a, int b) {
    int res = a + b;
    if (res >= MOD) res -= MOD;
    return res;
}

LL mul(LL a, LL b) {
    return (a * b) % MOD;
}

int main() {
    int N, S;
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    LL ans = 0;
    for (int i = 0; i < N; i++) {
        memset(ndp, 0, sizeof(ndp));
        for (int j = 0; j <= S; j++) {
            ndp[j] = dp[j];
            if (j >= A[i])
                ndp[j] = add(ndp[j], dp[j - A[i]]);
        }
        ndp[A[i]] = add(ndp[A[i]], i + 1);
        for (int j = 0; j <= S; j++)
            dp[j] = ndp[j];
        ans = add(ans, dp[S]);
    }
    printf("%lld\n", ans);
    return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
by Benq;
*/
