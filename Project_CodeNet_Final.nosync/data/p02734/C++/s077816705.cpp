#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <complex>
typedef long long int LL;
using namespace std;

// 插入此處

const int MOD = 998244353;

LL a[3005];
LL r_fix[3005][3005];

// 依次求得
// (1, 1)
// (1, 2), (2, 2)
// (1, 3), (2, 3), (3, 3)
// (1, 4), (2, 4), (3, 4), (4, 4)
// .....

// r_fix[i][j] 也可由動態規劃得到


int main() {
    int n, s;
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    // r_fix[0][0] = 1;
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            if (j < a[i]) {
                r_fix[i][j] = r_fix[i - 1][j];
            } else if (j == a[i]) {
                r_fix[i][j] = (r_fix[i - 1][j] + i) % MOD;
            } else {
                r_fix[i][j] = (r_fix[i - 1][j] + r_fix[i - 1][j - a[i]]) % MOD;
            }
        }
        ans += r_fix[i][s];
        ans %= MOD;
    }
    printf("%lld\n", ans);
}
