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
#include <functional>
#include <cassert>
//#include <numeric>
#pragma warning(disable:4996) 
 
typedef long long ll;
typedef unsigned long long ull;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
//const long long MOD = 1000000007;
const long long MOD = 998244353;

using namespace std;

ll dp[3005][3005];

void solve()
{
    int n, S;
    scanf("%d%d", &n, &S);

    vector<int> a(n);
    int i,j;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    dp[0][0] = 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= S; j++) {
            if (dp[i][j] == 0) continue;
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;

            int j2 = j + a[i];
            if (j2 <= S) {
                int mult = 1;
                if (j == 0) mult = mult * (i+1) %MOD;
                if (j2 == S) mult = mult * (n - i) %MOD;
                dp[i + 1][j2] = (dp[i + 1][j2] + dp[i][j] * mult) % MOD;
            }
        }
    }
    printf("%lld\n", dp[n][S]);

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
        //printf("Case #%d: ", t+1);
        solve();
    }
#endif
    return 0;
}

