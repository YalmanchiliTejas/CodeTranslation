#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#include <numeric>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

ll dp[200005][2];

void solve()
{
    int n;
    scanf("%d", &n);
    vector<ll> a(n), s0(n+1), s1(n+1);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (i = 0; i < n; i++) {
        s0[i + 1] = s0[i] + (i%2==0? a[i]: 0);
        s1[i + 1] = s1[i] + (i%2==1? a[i]: 0);
    }

    if (n % 2 == 0) {
        ll ans = MAX(s0[n], s1[n]);
        for (i = 0; i <= n / 2; i++) {
            ll ans0 = s0[2 * i] + s1[n] - s1[2 * i];
            ans = MAX(ans, ans0);
        }
        printf("%lld\n", ans);
    }
    else {
        ll ans = MAX(MAX(s0[n-1], s1[n-1]), s0[n]-s0[1]);
        int j;
        int m = n / 2;

        for (i = 0; i <= m; i++) {
            int j;
            for (j = 0; j < 2; j++) {
                dp[i][j] = -LINF;
            }
        }
        dp[0][0] = dp[0][1] = 0;
        for (i = 0; i < m; i++) {
            dp[i + 1][0] = MAX(dp[i + 1][0], dp[i][0] + a[2 * i]);
            dp[i + 1][1] = MAX(dp[i + 1][0], dp[i][0] + a[2 * i + 1]);
            dp[i + 1][1] = MAX(dp[i + 1][1], dp[i][1] + a[2 * i + 1]);
        }

        for (i = 0; i < n / 2; i++) {
            ll ans0 = dp[i][1] + s0[n] - s0[2*(i+1)];
            ans = MAX(ans, ans0);
        }
        for (i = 1; i < n / 2; i++) {
            ll ans0 = s0[2 * i] + s1[n] - s1[2 * (i + 1)];
            ans = MAX(ans, ans0);
        }
        printf("%lld\n", ans);      
    }

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T;
    scanf("%d", &T);
    int t;
    for(t=0; t<T; t++) {
        printf("Case #%d: ", t+1);
        solve();
    }
#endif
    return 0;
}

